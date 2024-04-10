#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 1e7 + 5;

int n, lp[N], a[1000005], f[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < N; i++)
        if(lp[i] == 0)
        {
            lp[i] = i;
            
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    if(lp[j] == 0)
                        lp[j] = i;
        }

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        while(a[i] > 1)
        {
            int x = lp[a[i]];

            while(lp[a[i]] == x)
                a[i] /= x;

            f[x]++;
        }
    }

    for(int i = 1; i < N; i++)
        f[i] += f[i - 1];

    int m;
    cin >> m;

    while(m--)
    {
        int l, r;
        cin >> l >> r;

        r = min(r, N - 1);
        l = min(l, N - 1);

        cout << f[r] - f[l - 1] << "\n";
    }
}