/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
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

map<pii,vi> t;
vector<pair<pii,pii>> sofa;
int d,n,m, ans[100000][4]; 

void test(int i) {
	t.clear();
	if (i == 0) {
		F0R(i,d) {
			if (sofa[i].f.f == sofa[i].s.f) t[{sofa[i].f.f,0}].pb(i);
			else t[{min(sofa[i].f.f,sofa[i].s.f),1}].pb(i);
		}
	} else if (i == 1) {
		F0R(i,d) {
			if (sofa[i].f.f == sofa[i].s.f) t[{-sofa[i].f.f,0}].pb(i);
			else t[{min(-sofa[i].f.f,-sofa[i].s.f),1}].pb(i);
		}
	} else if (i == 3) {
		F0R(i,d) {
			if (sofa[i].f.s == sofa[i].s.s) t[{-sofa[i].f.s,0}].pb(i);
			else t[{min(-sofa[i].f.s,-sofa[i].s.s),1}].pb(i);
		}
	} else if (i == 2) {
		F0R(i,d) {
			if (sofa[i].f.s == sofa[i].s.s) t[{sofa[i].f.s,0}].pb(i);
			else t[{min(sofa[i].f.s,sofa[i].s.s),1}].pb(i);
		}
	}
	int cnum = 0;
	for (auto a: t) {
		int temp = a.s.size();
		if (a.f.s == 0) {
			for (int b: a.s) ans[b][i] = cnum;
		} else {
			for (int b: a.s) ans[b][i] = cnum+temp-1;
		}
		cnum += temp;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> d >> n >> m; sofa.resize(d);
	F0R(i,d) cin >> sofa[i].f.f >> sofa[i].f.s >> sofa[i].s.f >> sofa[i].s.s;
	F0R(i,4) test(i);
	/*F0R(i,d) {
		F0R(j,4) cout << ans[i][j] << " ";
		cout << "\n";
	}*/
	
	int c[4]; F0R(i,4) cin >> c[i];
	F0R(i,d) {
		bool ok = 1;
		F0R(j,4) if (ans[i][j] != c[j]) ok = 0;
		if (ok) {
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
}