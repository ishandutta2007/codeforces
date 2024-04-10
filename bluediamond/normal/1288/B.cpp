#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int c = 0, p = 1;
        while (p <= (int) 1e8)
        {
            p *= 10;
            if (p - 1 > b)
            {
                break;
            }
            else
            {
                c++;
            }
        }
        cout << c * (ll) a << "\n";
    }
}