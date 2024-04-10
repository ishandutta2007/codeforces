#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int maxn = 100100;

#define B 4 //B
#define M 1000000007

struct matrix{
	int x[B][B];
	int *operator [] (int a) { return x[a]; }
	void clear(){
		memset(x, 0, sizeof(x));
	}
	void reset(){
		memset(x, 0, sizeof(x));
		for(int i = 0; i < B; ++i) x[i][i] = 1;
	}
}p, tr[maxn * 4];
void inc(int &a, int b) { a += b; if (a >= M) a -= M; }
matrix operator * (matrix &a, matrix &b){
	memset(p.x, 0, sizeof(p.x));
	for(int i = 0; i < B; i++)
		for(int j = 0; j < B; j++)
			for(int k = 0; k < B; k++)
				inc(p[i][j], (ll)a[i][k] * b[k][j] % M);
	return p;
}

int n, m;
vector<int> q;
vector<int> b[maxn];
int a[maxn];
int c[maxn], tot;
int ls[maxn * 4], rs[maxn * 4];
int pre[maxn], nex[maxn];
int rt[maxn];

int ask(int x) { int res = 0; for(; x; x -= x & -x) res += c[x]; return res; }
void add(int x) { for(; x <= q.size(); x += x & -x) c[x]++; }

int build(int l, int r, vector<int> &b){
	int t = ++tot;
	if(l == r){
		tr[t].reset();
		tr[t][0][1] = pre[b[l - 1]];
		tr[t][2][3] = nex[b[l - 1]];
		tr[t][1][2] = 1;
		return t;
	}
	int d = (l + r) >> 1;
	ls[t] = build(l, d, b); rs[t] = build(d + 1, r, b);
	tr[t] = tr[ls[t]] * tr[rs[t]];
	return t;
}

void modify(int t, int l, int r, vector<int> &b, int w, int c){
	if(l == r){
		tr[t].reset();
		if(c == 2){
			tr[t][0][1] = pre[b[l - 1]];
			tr[t][2][3] = nex[b[l - 1]];
			tr[t][1][2] = 1;
		}
		return;
	}
	int d = (l + r) >> 1;
	if(w <= d) modify(ls[t], l, d, b, w, c);
	else modify(rs[t], d + 1, r, b, w, c);
	tr[t] = tr[ls[t]] * tr[rs[t]];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		q.pb(a[i]);
	}
	sort(q.begin(), q.end());
	q.erase(unique(q.begin(), q.end()), q.end());
	for(int i = 1; i <= n; ++i){
		a[i] = lower_bound(q.begin(), q.end(), a[i]) - q.begin() + 1;
		pre[i] = ask(a[i]);
		add(a[i]);
		b[a[i]].pb(i);
	}
	memset(c, 0, sizeof(c));
	for(int i = n; i >= 1; --i){
		nex[i] = ask(a[i]);
		add(a[i]);
	}

	int now = 0;
	for(int i = 0; i < q.size(); ++i){
		rt[i + 1] = build(1, b[i + 1].size(), b[i + 1]);
		(now += tr[rt[i + 1]][0][3]) %= M;
	}
	
	scanf("%d", &m);
	while(m--){
		int t, x;
		scanf("%d%d", &t, &x);
		now = (now - tr[rt[a[x]]][0][3] + M) % M;
		int w = lower_bound(b[a[x]].begin(), b[a[x]].end(), x) - b[a[x]].begin() + 1;
		modify(rt[a[x]], 1, b[a[x]].size(), b[a[x]], w, t);
		(now += tr[rt[a[x]]][0][3]) %= M;
		printf("%d\n", now);
	}
	return 0;
}