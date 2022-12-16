#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;


const int NMAX = 200200;
int dp[NMAX][4];
int n;
vector<pii> adj[NMAX];
ll ans;

void dfs(int u, int p) {
    int sum[4] = {0,0,0,0};
    for(auto& vp : adj[u]) {
        int v = vp.first;
        if(v == p) continue;
        dfs(v, u);
        if(vp.second) {
            dp[u][2] += dp[v][2]+dp[v][0];
            dp[u][3] += 1+dp[v][3];
        } else {
            dp[u][0] += 1+dp[v][0];
            dp[u][1] += dp[v][1] + dp[v][3];
        }
    }
    //cerr << "~~~ " << u << " has " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << " " << dp[u][3] << endl;
    for(auto& vp : adj[u]) {
        int v = vp.first;
        if(v == p) continue;
        //cerr << " for " << v << endl;
        if(vp.second) {
            //cerr << "  " <<ans << endl;
            ans += (ll) (dp[u][3]-dp[v][3]-1)*(dp[v][3]+1); // this one is a three, other is a three
            //cerr << "  " <<ans << endl;
            /*ans += (ll) (dp[v][2]+dp[v][0])*(dp[u][3]-1-dp[v][3]); // this one is a two, other is a three
            //cerr << "  " <<ans << endl; */
            ans += (ll) (1+dp[v][3])*(dp[u][2]-dp[v][2]-dp[v][0]); // this is a three, other is a two
            //cerr << "  " <<ans << endl;
            ans += (ll) (1+dp[v][3])*(dp[u][0]); // this is a three, other is a zero
            //cerr << "  " <<ans << endl;
        } else {
            //cerr << "  " <<ans << endl;
            ans += (ll) (dp[u][0]-dp[v][0]-1)*(dp[v][0]+1); // this one is a zero, other is a zero
            //cerr << "  " <<ans << endl;
            ans += (ll) (dp[v][1]+dp[v][3])*(dp[u][0]-1-dp[v][0]); // this is a one, other is a zero
            //cerr << "  " <<ans << endl;
           /* ans += (ll) (dp[v][0]+1)*(dp[u][1]-dp[v][1]-dp[v][3]); // this is a zero, other is a one
            //cerr << "  " <<ans << endl;
            ans += (ll) (dp[v][0]+1)*(dp[u][3]); // this is a zero, other is a three
            //cerr << "  " <<ans << endl; */
        }
    }
    ans += dp[u][1] + dp[u][2] + dp[u][0]*2+dp[u][3]*2;
            //cerr << "  " <<ans << " . " << dp[u][1] << " " << dp[u][2] << " " << dp[u][0]*2 << " " << dp[u][3]*2 << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}