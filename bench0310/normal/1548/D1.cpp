#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> x(n+1,0);
    vector<ll> y(n+1,0);
    vector c(2,vector(2,ll(0)));
    auto add=[&](int i,int d){c[x[i]&1][y[i]&1]+=d;};
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
        x[i]/=2; y[i]/=2;
        add(i,1);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            add(i,-1);
            add(j,-1);
            ll a=(2*x[i]*2*y[j]-2*x[j]*2*y[i])/2;
            a=(a&1);
            ll g=((x[i]&1)!=(x[j]&1)||(y[i]&1)!=(y[j]&1));
            for(int u=0;u<2;u++)
            {
                for(int v=0;v<2;v++)
                {
                    ll b=g;
                    b^=((x[i]&1)!=u||(y[i]&1)!=v);
                    b^=((x[j]&1)!=u||(y[j]&1)!=v);
                    if(a==b) res+=c[u][v];
                }
            }
            add(i,1);
            add(j,1);
        }
    }
    cout << res/3 << "\n";
    return 0;
}