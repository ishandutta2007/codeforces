#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> v;

        int used[n + 1];

        for(int i = 0; i < n + 1; i++)
            used[i] = 0;

        int x = n;

        for(int i = n - 1; i >= 0; i--)
        {
            v.push_back(a[i]);
            used[a[i]] = 1;

            if(a[i] == x)
            {
                for(int j = (int)v.size() - 1; j >= 0; j--)
                {
                    cout << v[j] << ' ';
                    v.pop_back();
                }

                while(used[x])
                    x--;
            }
        }

        cout << "\n";
    }
}