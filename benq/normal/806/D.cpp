/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
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

ll n, mn = MOD;
ll best[2001],dist[2001][2001],ans;
vector<pair<int,pii>> order;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) FOR(j,i+1,n+1) {
	    cin >> dist[i][j];
	    dist[j][i] = dist[i][j];
	    order.pb({dist[i][j],{i,j}});
	    mn = min(mn,dist[i][j]);
	}
	// if (n == 2000) return 0;
	ans = mn*(n-1);
	sort(order.begin(),order.end());
	
	FOR(i,1,n+1) best[i] = 1e18;
	
	for (auto a: order) {
	    if (a.f == mn) {
	        best[a.s.f] = best[a.s.s] = 0;
	        continue;
	    }
	    if (best[a.s.f] == 1e18) {
    	    FOR(i,1,n+1) if (i != a.s.f) {
    	        if (dist[i][a.s.f] == a.f) best[a.s.f] = min(best[a.s.f],a.f-mn+best[i]);
    	        else best[a.s.f] = min(best[a.s.f],2*(a.f-mn)+best[i]);
    	    }
	    } else best[a.s.f] = min(best[a.s.f],a.f-mn+best[a.s.s]);
	    if (best[a.s.s] == 1e18) {
    	    FOR(i,1,n+1) if (i != a.s.s) {
    	        if (dist[i][a.s.s] == a.f) best[a.s.s] = min(best[a.s.s],a.f-mn+best[i]);
    	        else best[a.s.s] = min(best[a.s.s],2*(a.f-mn)+best[i]);
    	    }
	    } else best[a.s.s] = min(best[a.s.s],a.f-mn+best[a.s.f]);
	}
	FOR(i,1,n+1) cout << ans+best[i] << "\n";
}