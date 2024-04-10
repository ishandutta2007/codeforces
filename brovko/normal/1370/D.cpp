#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(k % 2)
    {
        int L = 0;
        int R = 1e9 + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int x = 0;

            for(int i = 0; i < n; i++)
                if(a[i] <= M)
                {
                    x++;
                    i++;
                }

            if(x >= k - k / 2)
                R = M;
            else L = M;
        }

        L = 0;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int x = 0;

            for(int i = 1; i < n - 1; i++)
                if(a[i] <= M)
                {
                    x++;
                    i++;
                }

            if(x >= k / 2)
                R = M;
            else L = M;
        }

        cout << R;
    }
    else
    {
        int L = 0;
        int R = 1e9 + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int x = 0;

            for(int i = 0; i < n - 1; i++)
                if(a[i] <= M)
                {
                    x++;
                    i++;
                }

            if(x >= k - k / 2)
                R = M;
            else L = M;
        }

        L = 0;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int x = 0;

            for(int i = 1; i < n; i++)
                if(a[i] <= M)
                {
                    x++;
                    i++;
                }

            if(x >= k / 2)
                R = M;
            else L = M;
        }

        cout << R;
    }
}