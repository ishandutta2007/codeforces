#include <bits/stdc++.h>
#define int long long
using namespace std;

int coss[100005][3];
int color[100005];

vector<int> elist[100005];
int succ[100005];

void dfs(int node, int p) {
    if(p != -1) succ[p] = node;
    for(int i:elist[node]) if(i != p) dfs(i, node);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    memset(succ, -1, sizeof succ);
    for(int i=0; i<3; i++) for(int j=0; j<n; j++) cin >> coss[j][i];
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        elist[u].push_back(v);
        if(elist[u].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
        elist[v].push_back(u);
        if(elist[v].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    int deg1 = -1;
    for(int i=0; i<n; i++) {
        if(elist[i].size() == 1) deg1 = i;
    }
    dfs(deg1, -1);
    long long best = 0xFFFFFFFFFFFFFFull;
    int ba = -1, bb = -1;
    for(int a=0; a<3; a++) {
        for(int b=0; b<3; b++) {
            if(a == b) continue;
            int t = deg1, t2 = succ[deg1];
            int h = a, h2 = b;
            int cost = coss[deg1][a] + coss[t2][b];
            while(succ[t2] != -1) {
                int coo;
                if(h == 0 && h2 == 1) coo=2;
                if(h == 1 && h2 == 2) coo=0;
                if(h == 2 && h2 == 0) coo=1;
                if(h == 0 && h2 == 2) coo=1;
                if(h == 1 && h2 == 0) coo=2;
                if(h == 2 && h2 == 1) coo=0;
                cost += coss[succ[t2]][coo];
                h = h2; h2 = coo;
                t = t2; t2 = succ[t2];
            }
            if(cost < best) {
                best = cost;
                ba = a; bb = b;
            }
        }
    }
    cout << best << endl;
            int t = deg1, t2 = succ[deg1];
            int h = ba, h2 = bb;
            color[t] = h; color[t2] = h2;
            while(succ[t2] != -1) {
                int coo;
                if(h == 0 && h2 == 1) coo=2;
                if(h == 1 && h2 == 2) coo=0;
                if(h == 2 && h2 == 0) coo=1;
                if(h == 0 && h2 == 2) coo=1;
                if(h == 1 && h2 == 0) coo=2;
                if(h == 2 && h2 == 1) coo=0;
                color[succ[t2]] = coo;
                h = h2; h2 = coo;
                t = t2; t2 = succ[t2];
            }
    for(int i=0; i<n; i++) {
        if(i != 0)cout << ' ';
        cout << color[i]+1;
    }
    cout << endl;
}