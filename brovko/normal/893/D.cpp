#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, d, a[100005], Max[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for(int i=0; i<n; i++)
        cin >> a[i];

    Max[n - 1] = d;

    for(int i=n-2; i>=0; i--)
    {
        Max[i] = min(d, Max[i + 1] - a[i + 1]);


        if(a[i] == 0 && Max[i] < 0)
        {
            cout << -1;
            return 0;
        }
    }

    if(Max[0] - a[0] < 0)
    {
        cout << -1;
        return 0;
    }

    int k = 0;
    int s = 0;

    for(int i=0; i<n; i++)
    {
        s += a[i];
        if(s < 0 && a[i] == 0)
        {
            k++;
            s = Max[i];
        }
    }

    cout << k;
}