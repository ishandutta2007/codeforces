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
        vector<int> h(n+1,0);
        for(int i=1;i<=n;i++) cin >> h[i];
        auto f=[&](int x,ll a,ll b)->bool
        {
            vector<int> g=h;
            int m=0;
            for(int i=1;i<=n;i++)
            {
                if((g[i]&1)==x)
                {
                    g[i]++;
                    a--;
                }
                m=max(m,g[i]);
            }
            if(a<0) return 0;
            b+=(a/2);
            for(int i=1;i<=n;i++) b-=(m-g[i])/2;
            return (b>=0);
        };
        ll l=-1,r=(1ll<<60);
        while(l<r-1)
        {
            ll m=(l+r)/2;
            ll a=((m+1)/2);
            ll b=m-a;
            if(f(0,a,b)||f(1,a,b)) r=m;
            else l=m;
        }
        cout << r << "\n";
    }
    return 0;
}