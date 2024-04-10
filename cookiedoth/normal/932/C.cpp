#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 2e6;
ll n, a, b, x, y, ans[mx];

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i <= n; ++i) {
        ll ex = n - a * i;
        if (ex % b == 0 && ex >= 0) {
            x = i;
            y = ex / b;
            break;
        }
    }
    if (x == 0 && y == 0) {
        cout << -1 << endl;
        return 0;
    }
    int ptr = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < a - 1; ++j) {
            ans[ptr + j] = ptr + j + 1;
        }
        ans[ptr + a - 1] = ptr;
        ptr += a;
    }
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < b - 1; ++j) {
            ans[ptr + j] = ptr + j + 1;
        }
        ans[ptr + b - 1] = ptr;
        ptr += b;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}