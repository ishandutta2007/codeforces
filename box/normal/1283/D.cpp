// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

struct use {
    int loc, dt, dist;
};

set<int> used;
vector<int> aray;
queue<use> bq;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    ll ans = 0; int cnt = 0;
    rep(i, n) {
        int v; cin >> v;
        used.insert(v);
        bq.push({v, 1, 0});
        bq.push({v, -1, 0});
    }
    while(cnt != m) {
        use at = bq.front(); bq.pop();
        int v = at.loc, dt = at.dt, dist = at.dist;
        if(!used.count(v+dt)) {
            bq.push({v+dt, dt, dist+1});
            used.insert(v+dt);
            aray.pb(v+dt);
            ans += (dist+1); cnt++;
            if(cnt == m) break;
        }
    }
    cout << ans << endl;
    rep(i, m) cout << aray[i] << ((i==m-1)?'\n':' ');
}