#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll inf=(1ll<<60);
    int n;
    ll a,b;
    cin >> n >> a >> b;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) cin >> v[i];
    set<int> s;
    auto add=[&](int x)
    {
        for(int i=2;i*i<=x;i++)
        {
            if((x%i)==0) s.insert(i);
            while((x%i)==0) x/=i;
        }
        if(x>1) s.insert(x);
    };
    for(int i=-1;i<=1;i++)
    {
        add(v[1]+i);
        add(v[n]+i);
    }
    ll res=inf;
    auto solve=[&](vector<int> x)->ll
    {
        int m=x.size();
        int c=0;
        for(int i=0;i<m;i++) c+=(x[i]==2);
        ll now=b*c;
        for(int i=0;i<m;i++)
        {
            c-=(x[i]==2);
            now=min(now,a*(i+1)+b*c);
        }
        return now;
    };
    for(int p:s)
    {
        vector<int> x(n+1,0);
        int l=n+1,r=0;
        for(int i=1;i<=n;i++)
        {
            if((v[i]%p)==0) x[i]=1;
            else if(((v[i]-1)%p)==0||((v[i]+1)%p)==0) x[i]=2;
            else
            {
                x[i]=0;
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(l==n+1)
        {
            vector<vector<ll>> dp(n+1,vector<ll>(3,inf));
            dp[0][0]=dp[0][1]=dp[0][2]=0;
            for(int i=1;i<=n;i++)
            {
                dp[i][0]=dp[i-1][0]+b*(x[i]==2);
                dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a;
                dp[i][2]=min(dp[i-1][1],dp[i-1][2])+b*(x[i]==2);
            }
            res=min(res,min(min(dp[n][0],dp[n][1]),dp[n][2]));
        }
        else
        {
            vector<int> one;
            for(int i=l-1;i>=0;i--) one.push_back(x[i]);
            vector<int> two;
            for(int i=r+1;i<=n;i++) two.push_back(x[i]);
            res=min(res,solve(one)+a*(r-l+1)+solve(two));
        }
    }
    cout << res << "\n";
    return 0;
}