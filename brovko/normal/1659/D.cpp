#include <bits/stdc++.h>
//#define int long long
#define ld long double
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

        vector <int> c(n);

        for(int i = 0; i < n; i++)
            cin >> c[i];

        vector <int> a(n + 1, -1);
        int Max = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[n - 1] != -1)
                break;

            if(a[i] == -1)
            {
                if(c[i] == 0)
                    a[i] = 0;
                else
                {
                    a[i] = 1;

                    for(int j = max(Max, i + 1); j < c[i]; j++)
                        a[j] = 1;

                    a[c[i]] = 0;
                    Max = c[i];
                }
            }
            else
            {
                if(a[i] == 0)
                {
                    for(int j = max(Max, i + 1); j < i + c[i]; j++)
                        if(a[j] == -1)
                            a[j] = 1;

                    a[i + c[i]] = 0;
                    Max = i + c[i];
                }
                else
                {
                    for(int j = max(Max, i + 1); j < c[i]; j++)
                        if(a[j] == -1)
                            a[j] = 1;

                    a[c[i]] = 0;
                    Max = c[i];
                }
            }
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << "\n";
    }
}