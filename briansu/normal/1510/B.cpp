#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SZ(a) ((int)a.size())

const int INF = 2e9;
const int MAXN = 2500;

struct edge {
    int to, cap, flow, rev;
};

vector<edge> G[MAXN];
int cur[MAXN], S, T;

int dfs(int u, int cap) {
    if (u == T || !cap) return cap;
    for (int &i = cur[u]; i < SZ(G[u]);) {
        auto &e = G[u][i++];
        if (e.cap != e.flow) {
            int df = dfs(e.to, min(cap, e.cap - e.flow));
            if (df) {
                e.flow += df;
                G[e.to][e.rev].flow -= df;
                return df;
            }
        }
    }
    return 0;
}

void add_edge(int u, int v, int cap) {
    G[u].pb(edge{v, cap, 0, SZ(G[v])});
    G[v].pb(edge{u, 0, 0, SZ(G[u]) - 1});
}

int cnt[MAXN], tag[MAXN];
int arr[MAXN], out[MAXN], done[MAXN];

int gen(int u) {
    if (u == T) return 1;
    for (int &i = cur[u]; i < SZ(G[u]);) {
        auto &e = G[u][i++];
        if (e.flow >= 1) {
            int rt = gen(e.to);
            if (rt) {
                e.flow -= 1;
                G[e.to][e.rev].flow += 1;
                if (u > T)
                    return u - T;
                return rt;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int d, n, ans = 0;
    cin >> d >> n;
    S = 1 << d, T = S + 1;
    for (int i = 1; i < (1 << d); ++i)
        cnt[i] = cnt[i & (i - 1)] + 1;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        arr[i] = 0;
        for (int j = 0; j < d; ++j)
            arr[i] |= int(s[j] - '0') << j;
        ans += cnt[arr[i]] + 1;
    }
    sort(arr + 1, arr + n + 1, [&](int a, int b) {
        return cnt[a] > cnt[b]; 
    });
    for (int i = 1; i <= n; ++i) {
        tag[arr[i]] = i + T;
        add_edge(tag[arr[i]], T, 1);
    }
    for (int i = 1; i < (1 << d); ++i) {
        for (int j = 0; j < d; ++j)
            if (!(i >> j & 1)) {
                add_edge(i, i | (1 << j), INF);
                if (tag[i | (1 << j)])
                    add_edge(i, tag[i | (1 << j)], 1);
            }
    }
    for (int i = 1; i <= n; ++i) {
        fill(cur, cur + T + T + 1, 0); 
        add_edge(S, arr[i], 1);
        if (!dfs(S, 1)) {
            G[S].pop_back();
            G[arr[i]].pop_back();
        }
    }
    for (auto e : G[S])
        if (e.flow == 1) {
            fill(cur, cur + T + T + 1, 0); 
            out[e.to] = gen(e.to);
            ans -= cnt[e.to] + 1;
        }
    cout << ans - 1 << "\n";
    int flag = 0;
    for (int i = n; i >= 1; --i)
        if (!done[i]) {
            if (flag)
                cout << " R";
            int nw = 0;
            for (int x = i; x; x = out[arr[x]]) {
                done[x] = 1;
                for (int j = 0; j < d; ++j)
                    if ((arr[x] >> j & 1) && !(nw >> j & 1)) {
                        if (flag)
                            cout << " ";
                        else
                            flag = 1;
                        cout << j;
                        nw |= 1 << j;
                    }
            }
        }
    cout << "\n";
}