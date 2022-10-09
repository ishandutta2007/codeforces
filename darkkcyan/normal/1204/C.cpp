#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 111
#define maxk 1010101
int n, k;
vector<int> gr[maxn];
int dis[maxn][maxn];
int p[maxk];
int dp[maxn], trace[maxk];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        string s; cin >> s;
        rep(f, n) if (s[f] == '1')
            gr[i].push_back(f);
    }

    rep(i, n) {
        fill(dis[i], dis[i] + n, maxn);
        queue<int> qu;
        for (qu.push(i), dis[i][i] = 0; len(qu); qu.pop()) {
            int u = qu.front();
            for (auto v: gr[u]) {
                if (dis[i][v] < maxn) continue;
                dis[i][v] = dis[i][u] + 1;
                qu.push(v);
            }
        }
    }

    cin >> k;
    rep(i, k) {
        cin >> p[i];
        --p[i];
    }

    rep(i, n) dp[i] = maxk;
    dp[p[0]] = 1;
    trace[0] = -1;

    vector<int> active(1, 0);
    rep1(i, k - 1) {
        auto temp = remove_if(active.begin(), active.end(), [&](int f) {
            return dis[p[f]][p[i - 1]] + 1 != dis[p[f]][p[i]];
        });
        active.resize(temp - active.begin());
        dp[p[i]] = maxk;
        for (auto f: active) {
            int cost = dp[p[f]] + 1;
            if (cost > dp[p[i]]) continue;
            dp[p[i]] = cost;
            trace[i] = f;
        }
        active.push_back(i);
    }

    vector<int> ans(1, k - 1);
    while (trace[ans.back()] != -1) ans.push_back(trace[ans.back()]);
    cout << len(ans) << '\n';
    for (int i = len(ans); i--; ) cout << p[ans[i]] + 1 << ' ';

    return 0;
}