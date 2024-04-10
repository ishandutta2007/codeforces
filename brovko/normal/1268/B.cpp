#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int b=0;
    int w=0;
    for(int i=0;i<n;i++)
        if(i%2==0)
        {
            b+=a[i]/2;
            w+=a[i]-a[i]/2;
        }
        else
        {
            b+=a[i]-a[i]/2;
            w+=a[i]/2;
        }
    cout << min(b, w);
}