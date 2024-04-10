#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    string only_a, only_b;
    for (int i = 1; i <= 300; i++)
    {
        only_a += 'a';
        only_b += 'b';
    }
    cout << only_a << endl;
    int x;
    cin >> x;
    if (x == 0) return 0;
    cout << only_b << endl;
    int y;
    cin >> y;
    if (y == 0) return 0;
    int n = 600 - x - y;
    string sol;
    for (int i = 0; i < n; i++)
    {
        sol += 'a';
    }
    int cnt_b = x - 300 + n;
    int cnt_a = y - 300 + n;
    if (cnt_a == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 'b';
        }
        cout << endl;
        int x;
        cin >> x;
        return 0;
    }
    if (cnt_b == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 'a';
        }
        cout << endl;
        int x;
        cin >> x;
        return 0;
    }
    int cur = x - 300 + n;
    for (int i = 0; i < n; i++)
    {
        sol[i] = 'b';
        int cur2;
        cout << sol << endl;
        cin >> cur2;
        if (cur2 == 0) return 0;
        if (cur < cur2)
        {
            sol[i] = 'a';
        }
        else
        {
            cur = cur2;
        }
    }
    cout << sol << endl;
}