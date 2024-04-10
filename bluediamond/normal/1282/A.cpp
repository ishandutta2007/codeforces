#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, ra;
        cin >> a >> b >> c >> ra;
        if (a > b)
        {
            swap(a, b);
        }
        int l = max(a, c - ra);
        int r = min(b, c + ra);
        int com;
        if (l <= r)
        {
            com = r - l;
        }
        else
        {
            com = 0;
        }
        cout << b - a - com << "\n";
    }
}