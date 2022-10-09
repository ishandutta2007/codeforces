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

int find_dis(int src, int dst, int x, int y) {
    int dis[10];
    memset(dis, -1, sizeof dis);
    queue<int> qu;
    for (auto i: {(src + x) % 10, (src + y) % 10}) {
        qu.push(i);
        dis[i] = 0;
    }
    for (; len(qu); qu.pop()) {
        int u = qu.front();
        for (auto v: {(u + x) % 10, (u + y) % 10}) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            qu.push(v);
        }
    }
    return dis[dst];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;

    int cnt[10][10];
    memset(cnt, 0, sizeof cnt);
    rep(i, len(s) - 1) cnt[s[i] - '0'][s[i + 1] - '0'] ++;

    rep(i, 10) {
        rep(f, 10) {
            int dis[10][10];
            rep(u, 10) rep(v, 10) dis[u][v] = find_dis(u, v, i, f);
            
            llong ans = 0;
            for (int u = 0; u < 10 and ans != -1; ++u) rep(v, 10) {
                if (cnt[u][v] == 0) continue;
                if (dis[u][v] == -1) {
                    ans = -1;
                    break;
                }
                // clog << u << ' ' << v << ' ' << cnt[u][v] << ' ' << dis[u][v] << endl;
                ans += dis[u][v] * cnt[u][v];
            }
            cout << ans << ' ';
            // clog << endl;
        }
        cout << '\n';
    }

    return 0;
}