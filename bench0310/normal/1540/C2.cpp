#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    int m=0;
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        m=max(m,c[i]);
    }
    vector<int> b(n+1,0);
    for(int i=2;i<=n;i++) cin >> b[i];
    for(int i=2;i<=n;i++) b[i]+=b[i-1];
    for(int i=2;i<=n;i++) b[i]+=b[i-1];
    const int lim=100000;
    int sum=0;
    int mn=lim;
    int mx=lim;
    auto f=[&](int x,int y)->int{return (x/y-(x<0&&(x%y)!=0));};
    for(int i=1;i<=n;i++)
    {
        sum+=c[i];
        mn=min(mn,f(-b[i],i));
        mx=min(mx,f(sum-b[i],i));
    }
    vector<int> res(mx-mn+2,0);
    for(int x=mn;x<=mx;x++)
    {
        vector<ll> dp(m*n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            vector<ll> ndp(m*n+1,0);
            ll s=0;
            for(int j=0;j<=m*n;j++)
            {
                s=add(s,dp[j]);
                if(j>c[i+1]) s=sub(s,dp[j-c[i+1]-1]);
                if(j-b[i+1]>=x*(i+1)) ndp[j]=s;
            }
            dp=ndp;
        }
        ll t=0;
        for(int j=0;j<=m*n;j++) t=add(t,dp[j]);
        res[x-mn]=t;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        x=clamp(x,mn,mx+1);
        cout << res[x-mn] << "\n";
    }
    return 0;
}