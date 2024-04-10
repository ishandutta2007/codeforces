#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], k[100005], x, Max;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
    {
        if(a[i] > x)
        {
            Max = x;
            x = a[i];
            k[a[i]]--;
        }
        else if(a[i] > Max)
                {
                    k[x]++;
                    Max = a[i];
                }
    }

    int Max2 = -1e9;

    for(int i=1; i<=n; i++)
        Max2 = max(Max2, k[i]);

    for(int i=1; i<=n; i++)
        if(k[i] == Max2)
    {
        cout << i;
        return 0;
    }
}