#include <bits/stdc++.h>
//#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, k, a[1000005], lp[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 2; i < 1000005; i++)
        if(lp[i] == 0)
        {
            lp[i] = i;

            if(i <= 1000000 / i)
                for(int j = i * i; j < 1000005; j += i)
                    {
                        if(lp[j] == 0)
                            lp[j] = i;
                    }
        }


    for(int i = 0; i < n; i++)
    {
        while(a[i] > 1)
        {
            int x = lp[a[i]];
            int y = 0;
            int z = 1;

            while(lp[a[i]] == x)
            {
                y++;
                a[i] /= x;
                z *= x;
            }

            if(k % x == 0 && k / x % z == 0);
                else
            {
                while(k % x == 0)
                    k /= x;
            }
        }
    }

    if(k == 1)
        cout << "Yes";
    else cout << "No";
}