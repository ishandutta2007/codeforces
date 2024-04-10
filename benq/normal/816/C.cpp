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

int col[100], row[100];
int mn = MOD, mn1 = MOD;

int main() {
	int n,m; cin >> n >> m;
	int g[100][100];
	F0R(i,n) F0R(j,m) cin >> g[i][j];
	
	F0R(i,n) {
		row[i] = g[i][0];
		mn = min(mn,g[i][0]);
	}
	F0R(i,n) row[i] -= mn;
	
	F0R(i,m) {
		col[i] = g[0][i];
		mn1 = min(mn1,g[0][i]);
	}
	F0R(i,m) col[i] -= mn1;
	if (g[0][0]-row[0]-col[0]<0) {
		cout << -1;
		return 0;
	}
	F0R(i,n) F0R(j,m) {
		if (g[i][j]-row[i]-col[j] != g[0][0]-row[0]-col[0]) {
			cout << -1;
			return 0;
		}
	}
	int ans = 0;
	vector<pair<string,int>> z;
	F0R(i,n) 
		F0R(j,row[i]) z.pb({"row ",i+1});
	
	F0R(i,m)
		F0R(j,col[i]) z.pb({"col ",i+1});
		
	if (n < m) {
		F0R(i,g[0][0]-row[0]-col[0]) F0R(j,n) 
			z.pb({"row ",j+1});
			
	} else if (n >= m) {
		F0R(i,g[0][0]-row[0]-col[0]) F0R(j,m) 
			z.pb({"col ",j+1});
	}
	
	cout << z.size() << "\n";
	F0R(i,z.size()) cout << z[i].f << z[i].s << "\n";
}