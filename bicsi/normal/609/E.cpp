#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 2;
const int MAXL = 20;
const int INF = 2e9;

int D[MAXN], A[MAXN], B[MAXN], C[MAXN], Parent[MAXL][MAXN], DP[MAXL][MAXN], Depth[MAXN];
bool Done[MAXN];

vector<pair<int, int>> G[MAXN];
priority_queue<pair<int, int>> Q;

int n;

long long Prim() {
    for(int i=1; i<=n; i++)
        D[i] = INF;

    D[1] = 0;
    Q.push({0, 1});

    long long total = 0;

    while(!Q.empty()) {
        auto top = Q.top();
        Q.pop();

        int node = top.second;
        if(-top.first != D[node] || Done[node]) continue;
        Done[node] = 1;

        total += D[node];

        for(auto e : G[node]) {
            int vec = e.first, cost = e.second;
            if(!Done[vec] && D[vec] > cost) {
                D[vec] = cost;
                Q.push({-cost, vec});

                Parent[0][vec] = node;
                DP[0][vec] = cost;
                Depth[vec] = Depth[node] + 1;
            }
        }
    }

    return total;
}

void doDP() {
    for(int i=1; i<MAXL; i++)
        for(int node=1; node<=n; node++) {
            Parent[i][node] = Parent[i-1][Parent[i-1][node]];
            DP[i][node] = max(DP[i-1][node], DP[i-1][Parent[i-1][node]]);
        }
}

int Solve(int a, int b) {
    if(Depth[a] < Depth[b]) swap(a, b);
    int delta = Depth[a] - Depth[b];

    int r = 0;
    for(int i=0; (1 << i) <= delta; i++) {
        if(delta & (1 << i)) {
            r = max(r, DP[i][a]);
            a = Parent[i][a];
        }
    }

    if(a == b) return r;

    for(int i=19; i>=0; i--) {
        if(Parent[i][a] != Parent[i][b]) {
            r = max(r, DP[i][a]);
            r = max(r, DP[i][b]);

            a = Parent[i][a];
            b = Parent[i][b];
        }
    }

    r = max(r, DP[0][a]);
    r = max(r, DP[0][b]);

    return r;

}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif

    int m, a, b, c;
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        cin>>A[i]>>B[i]>>C[i];
        G[A[i]].push_back({B[i], C[i]});
        G[B[i]].push_back({A[i], C[i]});
    }

    long long t = Prim();
    doDP();

    for(int i=1; i<=m; i++) {
        cout << t + C[i] - Solve(A[i], B[i]) << '\n';
    }


    return 0;
}