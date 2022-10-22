#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[200005], Min, Max, b[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]]++;
        }

    for(int i = 0; i <= n; i++)
    {
        if(b[i])
        {
            Min++;
            i += 2;
        }
    }

    for(int i = 0; i <= n; i++)
        if(b[i])
            Max++;

    for(int i = 1; i <= n; i++)
    {
        if(b[i-1] == 0 && b[i] > 0)
        {
            if(b[i] > 1)
                Max++;
            b[i]--;
        }

        if(b[i] > 1)
        {
            b[i]--;
            b[i+1]++;
            if(b[i+1] == 1)
                Max++;
        }
    }

    cout << Min << ' ' << Max;
}