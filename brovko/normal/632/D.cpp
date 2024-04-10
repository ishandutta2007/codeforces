#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[1000005], k[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        if(a[i] <= m)
            k[a[i]]++;
    }

    for(int i = m; i >= 1; i--)
    {
        for(int j = i + i; j <= m; j += i)
            k[j] += k[i];
    }

    int Max = 1;

    for(int i = 2; i <= m; i++)
    {
        if(k[i] > k[Max])
            Max = i;
    }

    cout << Max << ' ' << k[Max] << "\n";

    for(int i = 0; i < n; i++)
    {
        if(Max % a[i] == 0)
            cout << i + 1 << ' ';
    }
}