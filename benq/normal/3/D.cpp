#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pii> cost;
string par;
ll ans = 0;
int lazy[1<<17], arr[1<<17];

void push(int ind, int l, int r) {
	if (l != r) {
		lazy[2*ind] += lazy[ind];
		lazy[2*ind+1] += lazy[ind];
	}
	arr[ind] += lazy[ind];
	lazy[ind] = 0;
}

void update(int ind, int l, int r, int left, int right, int inc) {
	push(ind,l,r);
	if (left <= l && r <= right) {
		arr[ind] += inc;
		if (l != r) lazy[2*ind] += inc, lazy[2*ind+1] += inc;
		return;
	} 
	if (r<left || l>right) return;
	int m = (l+r)/2;
	update(2*ind,l,m,left,right,inc);
	update(2*ind+1,m+1,r,left,right,inc);
	arr[ind] = min(arr[2*ind],arr[2*ind+1]);
}

int query(int ind, int l, int r, int left, int right) {
	push(ind,l,r);
	if (left <= l && r <= right) return arr[ind];
	if (r<left || l>right) return MOD;
	int m = (l+r)/2;
	return min(query(2*ind,l,m,left,right),query(2*ind+1,m+1,r,left,right));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> par;
	F0R(i,par.length()) if (par[i] == '?') {
		pii c; cin >> c.f >> c.s;
		ans += c.f; c.f = (c.s-c.f);
		c.s = i;
		cost.pb(c);
	}
	F0R(i,par.length()) {
		if (par[i] == '?' || par[i] == '(') arr[i+(1<<16)] = 1;
		else arr[i+(1<<16)] = -1;
		if (i) arr[i+(1<<16)] += arr[i-1+(1<<16)];
		//cout << i << " " << arr[i+(1<<16)] << "\n";
	}
	//cout << "\n";
	FORd(i,1,1<<16) arr[i] = min(arr[2*i], arr[2*i+1]);
	
	sort(cost.begin(),cost.end());
	for (auto a: cost) {
		//cout << a.s << " " << query(1,0,(1<<16)-1,a.s,par.length()-1) << "\n";
		//cout << query(1,0,(1<<16)-1,par.length()-1,par.length()-1) << "\n";
		if (query(1,0,(1<<16)-1,a.s,par.length()-1) >= 2) {
			ans += a.f;
			update(1,0,(1<<16)-1,a.s,par.length()-1,-2);
			par[a.s] = ')';
		} else par[a.s] = '(';
		//cout << query(1,0,(1<<16)-1,par.length()-1,par.length()-1) << "\n";
	}
	//cout << query(1,0,(1<<16)-1,par.length()-1,par.length()-1) << "\n";
	F0R(i,par.length()) if (query(1,0,(1<<16)-1,i,i) < 0) {
		cout << -1;
		return 0;
	}
	if (query(1,0,(1<<16)-1,par.length()-1,par.length()-1) != 0) cout << -1;
	else cout << ans << "\n" << par;
}