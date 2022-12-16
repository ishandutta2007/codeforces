#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;


const int N = 100100;

map<int, ll> in[N];
map<int, ll> out[N];

int n, m;
int tr[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    srand(time(NULL));
    cin >> n >> m;
    for (int i=1; i<=m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        in[v][u] += w;
        out[u][v] += w;
    }

    vector<pii> ve;
    for (int i=1; i<=n; ++i) {
        ve.emplace_back(/*(max(out[i].size(), in[i].size())<<18)*/+rand()%(1<<18), i);
    }
    sort(ve.begin(), ve.end());

    for (int q=0; q<ve.size(); ++q) {
    //for (int u=1; u<=n; ++u) {
        int u = ve[q].second;
        // i -> u -> j
        auto it = out[u].begin();
        for (auto& pr : in[u]) {
            while (pr.second > 0 && it != out[u].end()) {
                ll amt = min(pr.second, it->second);
                it->second -= amt;
                pr.second -= amt;
                out[pr.first][it->first] += amt;
                in[it->first][pr.first] += amt;

                in[it->first][u] -= amt;
                out[pr.first][u] -= amt;

                if (it->second == 0) {
                    ++it;
                }
            }
            if (it == out[u].end()) break;
        }
        int z = 0;
        for (auto& pr : in[u]) {
            if (pr.second == 0) tr[z++] = pr.first;
        }
        for (int x=0; x<z; ++x) {
            in[u].erase(tr[x]);
            out[tr[x]].erase(u);
        }
        z = 0;
        for (auto& pr : out[u]) {
            if (pr.second == 0) tr[z++] = pr.first;
        }
        for (int x=0; x<z; ++x) {
            out[u].erase(tr[x]);
            in[tr[x]].erase(u);
        }
    }


    int mp = 0;
    int aa = 0;
    for (int u=1; u<=n; ++u) {
        for (auto& pr : out[u]) {
            mp += (pr.second != 0);
            ++aa;
        }
    }
    cerr << " !! " << aa << endl;
    cout << mp << "\n";
    for (int u=1; u<=n; ++u) {
        for (auto& pr : out[u]) {
            //if (pr.first == u) continue;
            if (pr.second != 0) {
                cout << u << " " << pr.first << " " << pr.second << "\n";
            }
        }
    }
    return 0;
}