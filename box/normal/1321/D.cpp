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

int dis[200005];
vector<int> elist[200005];
vector<int> elist2[200005];
vector<int> path;
queue<int> bq;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        elist[v].pb(u);
        elist2[u].pb(v);
    }
    int e; cin >> e;
    rep(i, e) { 
        int u; cin >> u;
        path.pb(u);
    }
    int t = path.back();
    memset(dis, -1, sizeof dis);
    dis[t] = 0; bq.push(t);
    while(!bq.empty()) {
        int u = bq.front(); bq.pop();
        for(int& v:elist[u]) if(dis[v] == -1) {
            dis[v] = dis[u] + 1;
            bq.push(v);
        }
    }
    int mi = 0, mx = 0;
    rep(i, e-1) {
        int u = path[i], v = path[i+1];
        if(dis[v] + 1 != dis[u]) {
            mi++;
            mx++;
        } else {
            int cnt = 0;
            for(int& k:elist2[u]) cnt += (dis[k] == dis[v]);
            if(cnt != 1) mx++;
        }
    }
    cout << mi << ' ' << mx << endl;
}