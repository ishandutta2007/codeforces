#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n, dp[101][2000];
vector<vi> posi;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) {
	    int t,d,p; cin >> t >> d >> p;
	    posi.pb({d,i,t,p});
	}
	sort(posi.begin(),posi.end());
	F0R(i,n) {
	    F0R(j,2000) dp[i+1][j] = dp[i][j];
	    F0R(j,posi[i][0]-posi[i][2]) 
	        dp[i+1][j+posi[i][2]] = max(dp[i+1][j+posi[i][2]],dp[i][j]+posi[i][3]);
	}
	pii bes = {0,0};
	F0R(i,2000) bes = max(bes,{dp[n][i],i});
	cout << bes.f << "\n";
	vi z;
	F0Rd(i,n) {
	    if (dp[i][bes.s] == dp[i+1][bes.s]) continue;
	    bes.s -= posi[i][2];
	    z.pb(posi[i][1]);
	}
	reverse(z.begin(),z.end());
	cout << z.size() << "\n";
	for (int i: z) cout << i << " ";
}

// read!
// ll vs. int!