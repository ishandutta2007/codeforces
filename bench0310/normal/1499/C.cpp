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
        int n;
        cin >> n;
        vector<ll> c(n+1,0);
        for(int i=1;i<=n;i++) cin >> c[i];
        ll res=(1ll<<60);
        ll x=c[1];
        ll y=c[2];
        ll sx=c[1];
        ll sy=0;
        int a=1,b=0;
        for(int i=2;i<=n;i++)
        {
            if(i&1)
            {
                a++;
                x=min(x,c[i]);
                sx+=c[i];
            }
            else
            {
                b++;
                y=min(y,c[i]);
                sy+=c[i];
            }
            res=min(res,sx+x*(n-a)+sy+y*(n-b));
        }
        cout << res << "\n";
    }
    return 0;
}