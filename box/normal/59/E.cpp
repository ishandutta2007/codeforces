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

int pre[3005][3005];
int dist[3005][3005];
vector<int> elist[3005];
vector<int> cannot[3005][3005];
queue<pii> bq;

pii bfs(int source, int targ) {
    bq.push({source, source});
    dist[source][source] = 0;
    while(!bq.empty()) {
        pii t = bq.front(); bq.pop();
        if(t.se == targ) return {dist[t.fi][t.se], t.fi};
        int pthead = 0;
        for(int& v:elist[t.se]) {
            if(pthead == cannot[t.fi][t.se].size() || cannot[t.fi][t.se][pthead] != v) {
                if(dist[t.se][v] == -1) {
                    dist[t.se][v] = dist[t.fi][t.se]+1;
                    pre[t.se][v] = t.fi;
                    bq.push({t.se, v});
                }
            } else if(pthead != cannot[t.fi][t.se].size() && cannot[t.fi][t.se][pthead] == v)
                pthead++;
        }
    }
    return {-1, -1};
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(dist, -1, sizeof dist);
    int n, m, k; cin >> n >> m >> k;
    while(m--) {
        int u, v; cin >> u >> v;
        elist[u].pb(v);
        elist[v].pb(u);
    }
    rep1(i, n) sort(all(elist[i]));
    while(k--) {
        int a, b, c; cin >> a >> b >> c;
        cannot[a][b].pb(c);
    }
    rep1(i, n) rep1(j, n) sort(all(cannot[i][j]));
    pii ans = bfs(1, n);
    cout << ans.fi << endl;
    if(ans.fi != -1) {
        stack<int> seq;
        int cur = n, curbefore = ans.se;
        seq.push(cur); seq.push(curbefore);
        while(curbefore != 1) {
            int t = pre[curbefore][cur];
            cur = curbefore; curbefore = t;
            seq.push(t);
        }
        bool f = true;
        while(seq.size()) {
            if(!f) cout << ' ';
            f = false;
            cout << seq.top();
            seq.pop();
        }
        cout << endl;
    }
}