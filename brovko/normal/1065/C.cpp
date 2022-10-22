#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[200005], ans, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);
    if(a[0]==a[n-1])
    {
        cout << 0;
        return 0;
    }
    int x=n-1;
    ans=1;
    r=0;
    for(int h=a[n-1];h>a[0];h--)
        {
            while(x>0 && a[x-1]>=h)
                x--;
            if(r+n-x<=k)
                r+=n-x;
            else
            {
                r=n-x;
                ans++;
            }
        }
    cout << ans;
}