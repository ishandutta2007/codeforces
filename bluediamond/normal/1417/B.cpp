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
        int n, val, tot = 0;
        cin >> n >> val;
        vector<int> col(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (2 * x < val)
            {
                col[i] = 0;
            }
            if (2 * x == val)
            {
                tot++;
                col[i] = tot % 2;
            }
            if (2 * x > val)
            {
                col[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << col[i] << " ";
        }
        cout << "\n";
    }
}