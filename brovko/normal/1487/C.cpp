#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
            a[i] = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(n % 2 == 0 && i % 2 == 0 && j - i == 1)
                    cout << 0 << ' ';
                else
                {
                    if(a[i] >= a[j])
                    {
                        cout << 1 << ' ';

                        a[i]--;
                        a[j]++;
                    }
                    else
                    {
                        cout << -1 << ' ';

                        a[i]++;
                        a[j]--;
                    }
                }
            }
        }

        cout << "\n";
    }
}