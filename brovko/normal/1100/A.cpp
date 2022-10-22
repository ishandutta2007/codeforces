#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[105], Max;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
        for(int b=0;b<k;b++)
    {
        int x=0;
        for(int i=0;i<n;i++)
            if(i%k!=b)
            {
                x+=a[i];
            }
        Max=max(Max, abs(x));
    }
    cout << Max;
}