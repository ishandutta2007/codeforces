#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200200;
const int maxs = 300000;

long long a[maxn];
long long cnt[maxs];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("point.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        int x = a[i];
        //cout << a[i] << " ";
        if (x == 0) continue;
        int k = i;
        while (x % 2 == 0) {
            k++;
            x /= 2;
        }
        cnt[k] += x;
    }
    //cout << endl;
    //return 0;
    int z = 0;
    for (int i = 0; i < maxs - 100; ++i) {
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
        if (cnt[i] != 0) z = i;
    }
    ll c = 0;
    for (int i = 0; i <= z; ++i) {
        if (cnt[i] != 0) {
            c = i;
            break;
        }
    }
    ll lst = 0;

    long long cur = 1;
    long long x = 0;
    bool fl2 = false;
    int fl = 0;
    long long s = 0;
    for (int i = z; i > c; i--) {
        if (abs(cnt[i]) > (4LL * k)) {
            cout << "0\n";
            return 0;
        }
        cnt[i - 1] += 2LL * cnt[i];
    }
    x = cnt[c];
    int ans = 0;
    //cout << x << endl;
    for (int i = c; i > n; i--) {
        x <<= 1;
        if (abs(x) > 2LL * k) break;
    }
    for (int i = min(c, n); i >= 0; --i) {
        if (abs(x) > 2LL * k) break;
        if (abs(a[i] - x) <= k && (i != n || a[i] - x != 0)) {
            ans++;
            //cout << i << " " << a[i] - x << endl;
        }
        x <<= 1;
    }
    cout << ans << "\n";

    return 0;
}