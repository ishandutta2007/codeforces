#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

int n,m,q;
vi child[1001];
pii comp[1001];
vector<pair<int,pii>> cur, cur1, seg[1<<20];
bool z;

int unite(int x, int y) {
	if (comp[x].f == comp[y].f) {
		if (comp[x].s == comp[y].s) return 0;
		return -1;
	}
	if (child[comp[x].f].size() < child[comp[y].f].size()) swap(x,y);
	
	bool b = (comp[x].s == comp[y].s);
	int cur = comp[y].f;
	for (int i: child[cur]) {
		comp[i].f = comp[x].f;
		child[comp[x].f].pb(i);
		comp[i].s ^= b;
	}
	return 1;
}

void solve() {
	cur1.clear();
	z = 1;
	FOR(i,1,n+1) {
		comp[i] = {i,0};
		child[i].clear();
		child[i].pb(i);
	}
	for (auto a: cur) {
		int t = unite(a.s.f,a.s.s);
		if (t >= 0) cur1.pb(a);
		if (t == 0) {
			z = 0;
			break;
		}
	}
}

vector<pair<int,pii>> me(vector<pair<int,pii>> a, vector<pair<int,pii>> b) {
    vector<pair<int,pii>> t;
    int i1 = 0, i2 = 0;
    while (i1<a.size() || i2<b.size()) {
	    if (i1 == a.size()) t.pb(b[i2++]);
	    else if (i2 == b.size()) t.pb(a[i1++]);
	    else {
	        if (a[i1] > b[i2]) t.pb(a[i1++]);
	        else t.pb(b[i2++]);
	    }
	}
	return t;
}

void build(int node) {
	cur = me(seg[2*node],seg[2*node+1]);
	solve();
	seg[node] = cur1;
}

vector<pair<int,pii>> query (int ind, int low, int high, int L, int R) {
	vector<pair<int,pii>> t;
	if (high<L || low>R) {
		vector<pair<int,pii>> e;
		return e;
	} else if (L <= low && high <= R) return seg[ind];
	int mid = (low+high)/2;
	auto a1 = query(2*ind,low,mid,L,R), a2 = query(2*ind+1,mid+1,high,L,R);
	cur = me(a1,a2);
	solve();
	return cur1;
}

int main() { 
	cin >> n >> m >> q;
	FOR(i,1,m+1) {
		pair<int,pii> t;
		cin >> t.s.f >> t.s.s >> t.f;
		seg[i+(1<<19)-1].pb(t);
	}
	for (int i = (1<<19)-1; i > 0; --i) build(i);
	F0R(i,q) {
		int l,r; cin >> l >> r;
		auto a = query(1,1,1<<19,l,r);
		if (!z) cout << a[a.size()-1].f << "\n";
		else cout << "-1\n";
	}
}