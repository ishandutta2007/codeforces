#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int nxt[1000][10], h[1000];
vector<int> ch[1000];
vector<int> anc[1000];
int pc=1;
int mv[1000];
int dp[505][11][505];
int dp2[505][11][505][11];

const int INF = 0x3f3f3f3f;

void insert(const string& s, int m) {
    int u = 1;
    for (int i=0; i<s.size(); ++i) {
        if (!nxt[u][s[i]-'0']) {
            nxt[u][s[i]-'0'] = ++pc;
            anc[pc].push_back(pc);
            anc[pc].insert(anc[pc].end(), anc[u].begin(), anc[u].end());
        }
        u = nxt[u][s[i]-'0'];
        h[u] = i+1;
    }
    mv[u] += m;
}

int n, K;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    anc[1].push_back(1);
    cin >> n >> K;
    for (int i=1; i<=n; ++i) {
        string si;
        int mi;
        cin >> si >> mi;
        insert(si, mi);
    }

    vector<pii> vv;
    for (int i=1; i<=pc; ++i) {
        vv.emplace_back(h[i], i);
        for (int j=0; j<10; ++j) {
            if (nxt[i][j]) {
                ch[i].push_back(nxt[i][j]);
            }
        }
    }
    sort(vv.begin(), vv.end());
    reverse(vv.begin(), vv.end());

    memset(dp, INF, sizeof dp);
    memset(dp2, INF, sizeof dp2);

    for (int rem=0; rem<=K; ++rem) {
        for (int xi=0; xi<vv.size(); ++xi) {
            int x = vv[xi].second;
            for (int ki=0; ki<anc[x].size(); ++ki) {
                int k=anc[x][ki];
                dp2[x][rem][k][0] = mv[x]*(h[x]-h[k]);
                for (int m=0; m<ch[x].size(); ++m) {
                    for (int z=0; z<=rem; ++z) {
                        int &q = dp2[x][rem][k][m+1];
                        q = min(q, dp2[x][z][k][m]+dp[ch[x][m]][rem-z][k]);
                    }
                }
                
                dp[x][rem][k] = dp2[x][rem][k][ch[x].size()];
                if (rem) {
                    dp[x][rem][k] = min(dp[x][rem][k], dp[x][rem-1][x]);
                }
            }
        }
    }
    cout << dp[1][K][1] << endl;
    return 0;
}