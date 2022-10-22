#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    int m=n;
    int ans=1;
    int k=0;

    for(int i=2;i<=n;i++)
        if(n%i==0)
    {
        ans*=i;
        int c=0;
        while(n%i==0)
        {
            n/=i;
            c++;
        }
        k=max(k, c);
    }

    if(ans==m)
    {
        cout << ans << ' ' << 0;
        return 0;
    }

    int f=1;
    int z=ans;
    while(z<1000000)
    {
        z*=z;
        if(z==m)
            f=0;
    }

    int x=1;
    int y=0;
    while(k>x)
    {
        x*=2;
        y++;
    }
    cout << ans << ' ' << y+f;
}