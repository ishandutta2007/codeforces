#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, c, a[1000005], ps[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> c;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            ps[a[i]]++;

        for(int i = 2; i <= c; i++)
            ps[i] += ps[i - 1];

        int F = 1;

        for(int i = 1; i <= c; i++)
            if(ps[i] > ps[i - 1])
            {
                for(int j = i; j <= c; j += i)
                    if(ps[min(j + i - 1, c)] - ps[j - 1] > 0 && ps[j / i] == ps[j / i - 1])
                        F = 0;
            }

        cout << (F ? "Yes\n" : "No\n");

        for(int i = 1; i <= c; i++)
            ps[i] = 0;
    }
}