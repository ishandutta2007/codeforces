#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;

    cout << a << " " << b << "\n";
    for (int i = 1; i <= n; i++)
    {
        string x, y;
        cin >> x >> y;
        if (a == x)
        {
            a = y;
        }
        else
        {
            b = y;
        }
        cout << a << " " << b << "\n";
    }
}