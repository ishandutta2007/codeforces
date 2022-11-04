#include <bits/stdc++.h>

using namespace std;

int mas[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    cout << 2 * a + min(1ll, b - a) + 2 * c << endl;
    return 0;
}