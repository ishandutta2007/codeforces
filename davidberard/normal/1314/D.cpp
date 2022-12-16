#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 88;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll d[N][N];
vector<pii> g[N][N];
ll f[N][12];
int n, k;

int taken[N];
int ord[N];

ll ans;
void solve(int rep) {
    if (rep == k/2-1) {
        ll cur = 0;
        ord[k/2] = 1;
        for (int i=1; i<=k/2; ++i) {
            //cerr << " ORD " << ord[i] << " : ";
            for (auto& pp : g[ord[i-1]][ord[i]]) {
                if (taken[pp.second]) {
                    continue;
                }
                cur += pp.first;
                //cerr << " c " << pp.first << " t " << pp.second << endl;
                break;
            }
        }
        ans = min(ans, cur);
        //cerr << " COST " << cur << endl;
        //cerr << endl;
        return;
    }
    for (int i=1; i<=n; ++i) {
        ord[rep+1] = i;
        taken[i]++;
        solve(rep+1);
        taken[i]--;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            cin >> d[i][j];
        }
    }
    ord[0] = 1;
    taken[1] = 1;
    ord[k/2] = n;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            for (int z=1; z<=n; ++z) {
                if (i == j || j == z) continue;
                g[i][z].emplace_back(d[i][j]+d[j][z], j);
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        for (int z = 1; z<=n; ++z) {
            g[i][z].emplace_back(80LL*0x3f3f3f3f, 81);
            sort(g[i][z].begin(), g[i][z].end());
            while (g[i][z].size() > 6) g[i][z].pop_back();
        }
    }
    ans = INF;
    solve(0);
    cout << ans << "\n";
    return 0;
}