#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int w,h;
        cin >> w >> h;
        ll res=0;
        ll y=h;
        for(int o=0;o<2;o++)
        {
            ll x=0;
            for(int i=0;i<2;i++)
            {
                int k;
                cin >> k;
                ll a;
                cin >> a;
                for(int j=1;j<=k-1;j++)
                {
                    ll b;
                    cin >> b;
                    x=max(x,b-a);
                }
            }
            res=max(res,x*y);
            y^=(w^h);
        }
        cout << res << "\n";
    }
    return 0;
}