#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 2000;
int inv, n, m, a[mx];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i])
                inv++;
        }
    }
    inv = inv % 2;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int len = (r - l + 1);
        if ((len * (len - 1) / 2) % 2 == 1) {
            inv ^= 1;
        }
        if (inv == 0)
            cout << "even" << '\n';
        else
            cout << "odd" << '\n';
    }
    return 0;
}