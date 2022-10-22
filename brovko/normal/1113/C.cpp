#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[300005], x[300005], b[3000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        x[i+1]=(x[i]^a[i]);

    n++;

    for(int i=0;i<n;i++)
        if(i%2==0)
            b[x[i]]++;

    int ans=0;

    for(int i=0;i<=3000005;i++)
        if(b[i]>1)
            ans+=b[i]*(b[i]-1)/2;

    for(int i=0;i<3000005;i++)
        b[i]=0;

    for(int i=0;i<n;i++)
        if(i%2)
            b[x[i]]++;

    for(int i=0;i<=3000005;i++)
        if(b[i]>1)
            ans+=b[i]*(b[i]-1)/2;

    cout << ans;
}