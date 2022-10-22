#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    int L = 0;
    int R = 25e8;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int K = k;

        for(int i = 0; i < n; i++)
        {
            if(a[i] * M > b[i])
            {
                K -= a[i] * M - b[i];

                if(K < 0)
                    K = -1;
            }
        }

        if(K < 0)
            R = M;
        else L = M;
    }

    cout << L;
}