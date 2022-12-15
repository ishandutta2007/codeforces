#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

// const int N = 1000;
// bool vis[N + 5];
// 
// void dfs(int now) {
//     vis[now] = 1;
//     for (int i = 1; i <= now; i++)
//         if ((now&i) == i && now + i <= N && !vis[now + i])
//             dfs(now + i);
// }

bool cal(ll x, ll y) {
    if (y < x) return 0;
    int cnt = 0;
    while (x > 0 || y > 0) {
        if (x & 1) cnt++;
        if (y & 1) {
            if (cnt) cnt--;
            else return 0;
        }
        x >>= 1, y >>= 1;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // for (int i = 1; i <= N; i++) {
    //     memset(vis, 0, sizeof(vis));
    //     dfs(i);
    //     for (int j = i; j <= N; j++) {
    //         // cerr << bitset<6>(i) << " " << bitset<6>(j) << " " << vis[j] << "\n";
    //         assert(cal(i, j) == vis[j]);
    //     }
    // }    
    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        if (cal(x, y)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}