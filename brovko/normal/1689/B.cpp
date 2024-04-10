#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> p(n);

        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }

        if(n == 1)
        {
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            if(p[i] == i)
            {
                if(i == n - 3 && p[n - 1] == n - 1)
                {
                    cout << i + 2 << ' ' << i + 3 << ' ' << i + 1 << " ";
                    i += 2;
                }
                else
                {
                    cout << i + 2 << ' ' << i + 1 << " ";
                    i++;
                }
            }
            else
            {
                if(i == n - 2 && p[n - 1] == n - 1)
                {
                    cout << n << ' ' << i + 1 << ' ';
                    i++;
                }
                else cout << i + 1 << ' ';
            }
        }

        cout << "\n";
    }
}