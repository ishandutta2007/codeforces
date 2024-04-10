#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 3000;
int n, a[mx], g[mx][mx], len = mx, ones = 0;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        g[i][i] = a[i];
        for (int j = i + 1; j < n; ++j) {
            g[i][j] = gcd(g[i][j - 1], a[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (g[i][j] == 1)
                len = min(len, j - i + 1);
        }
    }
    if (len == mx) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1)
            ones++;
    }
    if (ones > 0) {
        cout << n - ones << endl;
        return 0;
    }
    int x = len - 1;
    cout << x + (n - 1) << endl;
    return 0;
}