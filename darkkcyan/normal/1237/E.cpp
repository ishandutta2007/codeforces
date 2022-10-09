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

#define maxn 1010101
llong dp[2][2][maxn] = {0};
llong tree_size[maxn] = {0};
void brute() {
    dp[0][0][0] = dp[1][0][0] = dp[0][1][0] = dp[1][1][0] = 1;
    dp[0][0][1] = 1;
    dp[1][1][1] = 1;
    tree_size[0] = 0;
    tree_size[1] = 1;
    for (int n = 2; n < 10000; ++n) {
        rep(start, 2) rep(head, 2) {
            tree_size[n] = INT_MAX;
            rep(left_size, n) tree_size[n] = min(tree_size[n], tree_size[left_size] + tree_size[n - left_size - 1] + n);

            rep(left_size, n) {
                if (head != ((left_size & 1) ^ start)) continue;
                int right_size = n - left_size - 1;
                if (tree_size[left_size] + tree_size[right_size] + n != tree_size[n]) continue;
                dp[start][head][n] += dp[start][!head][left_size] * dp[!head][head][right_size];
                // clog << "from " << left_size << ' ' << right_size << endl;
            }
        }
        if (dp[0][0][n] or dp[1][0][n] or dp[0][1][n] or dp[1][1][n]) clog << n << endl;
    }
}

int main(void) {
    // brute();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    llong n; cin >> n;
    bool up = true;
    for (llong i = 2, cnt = 60; cnt--; ) {
        if (i == n or i - 1 == n) {
            // clog << i << endl;
            cout << 1;
            return 0;
        }
        i *= 2;
        if (up) ++i;
        up = !up;
    }
    cout << 0;

    return 0;
}