#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int x_min, x_max;
    int y_min, y_max;

    int n;
    cin >> n;
    cin >> x_min >> y_min;

    x_max = x_min;
    y_max = y_min;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        x_min = min(x_min, x);
        x_max = max(x_max, x);

        y_min = min(y_min, y);
        y_max = max(y_max, y);
    }

    int a = max(y_max - y_min, x_max - x_min);

    cout << 1LL * a * a << endl;

    return 0;
}