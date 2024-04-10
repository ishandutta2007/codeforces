#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;
const int MAXN = 5e5;

int A[MAXN], B[MAXN], DA[MAXN], DB[MAXN];
vector<pair<long long, int>> IA, IB;
int n, m, k, s;

bool good(int cand, bool out) {
    for(int i=0, j=k; i<=k; i++, j--) {
        if(i < IA.size() && j < IB.size()) {

            if(IA[i].first > INF || IB[j].first > INF)
                continue;

            if(1LL * s < 1LL * IA[i].first * A[DA[cand]] + 1LL * IB[j].first * B[DB[cand]])
                continue;

            if(out) {
                for(int z=1; z<=i; z++) cout << IA[z].second << " " << DA[cand] << '\n';
                for(int z=1; z<=j; z++) cout << IB[z].second << " " << DB[cand] << '\n';
            }

            return true;
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif

    cin>>n>>m>>k>>s;

    A[0] = B[0] = INF;
    for(int i=1; i<=n; i++) cin>>A[i];
    for(int i=1; i<=n; i++) cin>>B[i];

    for(int i=1; i<=n; i++) {
        DA[i] = min(DA[i-1], i, [](int a, int b) {return A[a] < A[b];});
        DB[i] = min(DB[i-1], i, [](int a, int b) {return B[a] < B[b];});
    }

    IA.push_back({0, 0});
    IB.push_back({0, 0});
    int t, c;
    for(int i=1; i<=m; i++) {
        cin>>t>>c;
        if(t == 1) IA.push_back({c, i});
        else IB.push_back({c, i});
    }

    sort(IA.begin(), IA.end());
    sort(IB.begin(), IB.end());

    for(int i=1; i<IA.size(); i++) IA[i].first += IA[i-1].first;
    for(int i=1; i<IB.size(); i++) IB[i].first += IB[i-1].first;

    int sol = 0;
    for(int step = (1 << 19); step; step >>= 1)
        if(sol + step <= n && !good(sol + step, 0))
            sol += step;

    if(sol == n) cout << -1;
    else {
        cout << ++sol << '\n';
        good(sol, 1);
    }

    return 0;
}