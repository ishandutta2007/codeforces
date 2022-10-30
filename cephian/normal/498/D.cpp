#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
int a[N];
int segt[4*N],l[4*N],r[4*N],st[4*N][60],rc[4*N][60],touch[4*N];

int ctr=1;
void build(int v, int i, int j) {
	touch[v] = 1;
	l[v]=i;
	r[v]=j;
	if(i==j) return;
	build(v*2,i,(i+j)/2);
	build(v*2+1,(i+j)/2+1,j);
}

int calc(int v, int t) {
	if(touch[v] != rc[v][t]) {
		rc[v][t] = touch[v];
		if(l[v] == r[v]) {
			st[v][t] = 1 + (t%a[l[v]]==0);
		} else {
			int t1 = calc(v*2,t);
			st[v][t] = t1 + calc(v*2+1,(t+t1)%60);
		}
	}
	return st[v][t];
}

int qr(int v, int x, int y, int t) {
	int m = (l[v]+r[v])/2;
	if(r[v] < x || y <= l[v]) {
		return 0;
	}
	if(x <= l[v] && r[v] < y) {
		return calc(v,t);
	}
	int t1 = qr(v*2,x,y,t);
	int t2 = t1+qr(v*2+1,x,y,(t+t1)%60);
	return t2;
}

int query(int x, int y) {
	return qr(1,x,y,0);
}

void ud(int v, int i) {
	if(i < l[v] || r[v] < i) return;
	touch[v] = ctr;
	if(l[v] != r[v]) {
		ud(v*2,i);
		ud(v*2+1,i);
	}
}

void update(int x, int y) {
	a[x] = y;
	++ctr;
	ud(1,x);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,q;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> q;
	build(1,1,n);
	while(q--) {
		string s;
		int x,y;
		cin >> s >> x >> y;
		if(s[0]=='A') {
			cout << query(x,y) << "\n";
		} else {
			update(x,y);
		}
	}	
	return 0;
}