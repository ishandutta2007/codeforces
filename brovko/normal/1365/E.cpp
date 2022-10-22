#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[505], Max;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];

    if(n == 1)
    {
        cout << a[0];
        return 0;
    }

    if(n == 2)
    {
        cout << (a[0] | a[1]);
        return 0;
    }

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++)
                Max = max(Max, (a[i] | a[j] | a[k]));

    cout << Max;
}