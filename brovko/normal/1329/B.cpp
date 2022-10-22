#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 wepofj

using namespace std;

int t, d, m, k;

int add(int x, int y)
{
    return (x+y)%m;
}

int mul(int x, int y)
{
    return x*y%m;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> d >> m;
        int ans=1;
        for(int i=0;i<35;i++)
        {
            k=max(0ll, min((1ll << i+1)-(1ll << i), d+1-(1ll << i)));
            k++;
            ans=mul(ans, k);
        }
        ans=add(ans, m-1);
        cout << ans << endl;
    }
}