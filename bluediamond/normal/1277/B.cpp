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
        int n;
        cin >> n;
        set<int> vals;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            while (x % 2 == 0)
            {
                vals.insert(x);
                x /= 2;
            }
        }
        cout << (int) vals.size() << "\n";
    }
}