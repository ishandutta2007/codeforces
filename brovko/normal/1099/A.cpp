#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int w, h, u1, d1, u2, d2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    int ans=w;
    for(int i=h; i>0; i--)
    {
        ans+=i;
        if(i==d1)
            ans-=u1;
        if(i==d2)
            ans-=u2;
        ans=max(ans, 0ll);
    }
    cout << ans;
}