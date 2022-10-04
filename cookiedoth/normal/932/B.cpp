#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;
const int mx = 2e6;
int a[mx], n;
vector<int> t[10];

int func(int x) {
    int res = 1;
    while (x > 0) {
        int d = x % 10;
        if (d != 0)
            res *= d;
        x /= 10;
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }
    for (int i = 10; i < mx; ++i) {
        a[i] = a[func(i)];
    }
    for (int i = 0; i < mx; ++i) {
        t[a[i]].push_back(i);
    }
    int l, r, k;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r >> k;
        int x = lower_bound(t[k].begin(), t[k].end(), r + 1) - t[k].begin();
        int y = lower_bound(t[k].begin(), t[k].end(), l) - t[k].begin();
        cout << x - y << '\n';
    }
    return 0;
}