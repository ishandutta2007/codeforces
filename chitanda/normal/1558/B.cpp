#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int f[4000005], tag[4000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    f[1] = 1;
    int sum = 0, cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur = (cur + tag[i]) % m;

        f[i] = (f[i] + sum) % m;
        f[i] = (f[i] + cur) % m;

        for (int j = 2; j * i <= n; ++j) {
            int k = min(n + 1, (i + 1) * j);
            tag[j * i] = (tag[j * i] + f[i]) % m;
            tag[k] = (tag[k] - f[i] + m) % m;
        }

        sum = (sum + f[i]) % m;
        // printf("%d:%d\n", i, f[i]);
    }
    cout << f[n] << "\n";

    /*
    f[1] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = (f[i] + sum) % m;

        for (int j = 2, k; j <= i; j = k + 1) {
            k = i / (i / j);
            // printf("%d-%d\n", j, k);
            f[i] = (f[i] + (ll)f[i / j] * (k - j + 1)) % m;
        }
        sum = (sum + f[i]) % m;
        // printf("%d:%d\n", i, f[i]);
    }
    cout << f[n] << "\n";
    */
    return 0;
}