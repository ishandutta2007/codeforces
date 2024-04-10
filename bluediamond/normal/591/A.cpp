#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, p, q;
    cin >> l >> p >> q;
    /// p * t + q * t = l
    /// t = l / (p + q)
    /// p * l / (p + q)
    cout << fixed << setprecision(6) << 1.0 * p * l / (p + q) << "\n";
}