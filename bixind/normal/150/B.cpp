#include <iostream>
#include <vector>

using namespace std;

int d[3000];

int pr(int i) {
    if (d[i] == i)
        return i;
    return (d[i] = pr(d[i]));
}

void mrg(int a, int b) {
    a = pr(a);
    b = pr(b);
    if (a == b)
        return;
    d[b] = a;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        d[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int sh = 0;
        for (int j = k - 1; j >= 0; j -= 2, ++sh) {
            if (sh <= i && i - sh + k <= n && i + j < n) {
                mrg(i, i + j);
//                cout << i << ' ' << i + j << endl;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (d[i] == i)
            ++cnt;
    long long mod = 1e9 + 7;
    long long ans = 1;
    for (int i = 0; i < cnt; ++i) {
        ans = (ans * m) % mod;
    }
    cout << ans << endl;
    return 0;
}