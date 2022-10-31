#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int f[1000005];
int d[1000005];

map<int, int> m;

void div(int n) {
    if (n == 1)
        return;
    ++m[f[n]];
    div(n / f[n]);
}

int divisors(int n) {
    m.clear();
    div(n);
    int ans = 1;
    for (auto a : m)
        ans *= a.second + 1;
    return ans;
}

int main() {
    for (int i = 1; i < 1000005; ++i)
        f[i] = i;

    for (int i = 2; i <= 1000; ++i)
        if (f[i] == i)
            for (int j = i * i; j < 1000005; j += i)
                f[j] = i;
    for (int i = 1; i < 1000005; ++i)
        d[i] = divisors(i);

    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            for (int k = 1; k <= c; ++k)
                ans = (ans + d[i * j * k]) % 1073741824;
    cout << ans << "\n";
}