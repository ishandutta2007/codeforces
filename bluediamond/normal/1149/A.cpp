#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int f2 = 0, f1 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        f2 += (x == 2);
        f1 += (x == 1);
    }
    if (f2 == n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "2 ";
        }
        cout << "\n";
        return 0;
    }
    if (f1 == n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "1 ";
        }
        cout << "\n";
        return 0;
    }
    cout << "2 1 ";
    for (int i = 1; i < f2; i++)
    {
        cout << "2 ";
    }
    for (int i = 1; i < f1; i++)
    {
        cout << "1 ";
    }
    cout << "\n";
}