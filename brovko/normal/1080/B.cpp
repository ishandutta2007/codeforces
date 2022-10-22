#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int q, l, r;

int f(int x)
{
    if(x%2)
        return -x;
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        int ans=0;
        if(r-l<5)
        {
            for(int i=l;i<=r;i++)
                ans+=f(i);
        }
        else
        {
            if(l%2==0)
            {
                ans+=f(l);
                l++;
            }
            if(r%2)
            {
                ans+=f(r);
                r--;
            }

            ans+=(r-l+1)/2;
        }

        cout << ans << "\n";
    }
}