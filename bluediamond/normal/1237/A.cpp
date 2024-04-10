#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int dv(int x)
{
    if (x % 2 == 0 || x > 0)
    {
        return x / 2;
    }
    return x / 2 - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += dv(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s < 0 && a[i] % 2)
        {
            cout << dv(a[i]) + 1 << "\n";
            s++;
        }
        else
        {
            cout << dv(a[i]) << "\n";
        }
    }
}