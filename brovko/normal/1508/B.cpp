#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        k--;

        vector <int> v;

        for(int i = 0; i < n - 1; i++)
        {
            v.push_back(k % 2);
            k /= 2;
        }

        v.push_back(0);

        int y = n;

        for(int i = 0; i < n; i++)
        {
            if(v[i] == 0)
            {
                a[i] = y;
                y--;
            }
            else
            {
                while(i < n && v[i] == 1)
                    i++;

                a[i] = y;
                y--;

                int j = i;

                i--;

                while(i >= 0 && v[i] == 1)
                {
                    a[i] = y;
                    y--;
                    i--;
                }

                i = j;
            }
        }

        if(k > 0)
            cout << "-1\n";
        else
        {
            for(int i = n - 1; i >= 0; i--)
                cout << a[i] << ' ';

            cout << "\n";
        }
    }
}