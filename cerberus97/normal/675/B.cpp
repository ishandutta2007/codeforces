#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, d, x[6];
    long long ans = 0;

    cin >> n >> a >> b >> c >> d;

    for (x[1] = 1; x[1] <= n; ++x[1])
    {
        x[2] = x[1] + b - c;
        x[4] = x[1] + a - d;
        x[5] = x[2] + a - d;

        if (x[2] < 1 or x[2] > n)
            continue;

        if (x[4] < 1 or x[4] > n)
            continue;

        if (x[5] < 1 or x[5] > n)
            continue;

        ++ans;
    }

    cout << ans * n;
}