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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int g = 0;
        while (!a.empty())
        {
            int x = 1, val = 0, step = 0, it;
            for (auto &y : a)
            {
                int v = __gcd(g, y);
                if (v > val)
                {
                    x = y;
                    val = v;
                    it = step;
                }
                step++;
            }
            cout << x << " ";
            vector<int> b;
            for (int i = 0; i < (int) a.size(); i++)
            {
                if (i != it)
                {
                    b.push_back(a[i]);
                }
            }
            a = b;
            g = val;
        }
        cout << "\n";
    }
    return 0;
}