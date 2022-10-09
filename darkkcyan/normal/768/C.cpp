#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()

#define maxn 1030

int n, x, k;
vi a;
int cnt[2][maxn] = {0};

int main() {
#ifndef ONLINE_JUDGE 
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> x;

    for (int i = n; i--; ) {
        int t; cin >> t; cnt[0][t]++;
    }

    int t = 0;
    for (int i = 0; i < k; ++i) {
        int cur = 0;
        memset(cnt[!t], 0, sizeof cnt[t]);
        for (int i = 0; i < maxn; ++i) {
            int a = cnt[t][i] / 2, b = cnt[t][i] - a;
            if (cur & 1) swap(a, b);
            cnt[!t][i] += a;
            cnt[!t][i ^ x] += b;
            cur += a + b;
        }
        t ^= 1;
    }

    int ma = -1, mi = inf(int);
    for (int i = maxn; i--; ) {
        if (cnt[t][i]) ma = max(ma, i), mi = min(mi, i);
    }
    cout << ma << ' ' << mi;

    return 0;
}