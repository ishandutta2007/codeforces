#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;

    long long ans = 0;
    while (a > 0 && b > 0) {
        if (a >= b) {
            ans += a / b;
            a %= b;
        } else {
            ans += b / a;
            b %= a;
        }
    }
    cout << ans << endl;

    return 0;
}