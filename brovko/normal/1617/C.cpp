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

        sort(a, a + n);

        int k = n, F = 0;

        int b[n + 1];

        for(int i = 0; i < n + 1; i++)
            b[i] = 0;

        int mex = 1;

        for(int i = 0; i < n; i++)
        {
            if(a[i] <= n && b[a[i]] == 0)
            {
                k--;
                b[a[i]]++;
            }
            else
            {
                while(mex <= n && b[mex])
                    mex++;

                if(a[i] <= 2 * mex)
                    F = 1;
                    
                mex++;
            }
        }

        if(F)
            cout << "-1\n";
        else cout << k << "\n";
    }
}