#include <iostream>

using namespace std;

int a[110000];

int solve()
{
    int n, u, v;
    cin >> n >> u >> v;
    bool same = true;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] != a[i - 1])
            same = false;
        if (i > 0 && abs(a[i] - a[i - 1]) > 1)
            zero = true;
    }
    if (zero)
        return 0;
    if (same)
        return v + min(v, u);
    else
        return min(v, u);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
        cout << solve() << endl;
    return 0;
}