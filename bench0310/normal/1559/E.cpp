#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v(n+1,{0,0});
    for(int i=1;i<=n;i++) cin >> v[i][0] >> v[i][1];
    const int mod=998244353;
    auto add=[&](int a,int b)->int{return a+b-(a+b>=mod?mod:0);};
    auto sub=[&](int a,int b)->int{return a-b+(a-b<0?mod:0);};
    vector<int> g(m+1,0);
    for(int d=1;d<=m;d++)
    {
        int sz=(m/d);
        vector<int> dp(sz+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            auto [tl,tr]=v[i];
            vector<int> q(sz+1,0);
            int l=-1,r=-1;
            for(int j=1;j<=sz;j++)
            {
                if(tl<=j*d&&j*d<=tr)
                {
                    if(l==-1) l=j;
                    r=j;
                }
            }
            vector<int> sum(sz+1,0);
            sum[0]=dp[0];
            for(int j=1;j<=sz;j++) sum[j]=add(sum[j-1],dp[j]);
            auto s=[&](int a,int b)->int
            {
                if(b<0) return 0;
                a=max(a,0);
                return sub(sum[b],(a>0?sum[a-1]:0));
            };
            vector<int> ndp(sz+1,0);
            if(l!=-1) for(int j=0;j<=sz;j++) ndp[j]=s(j-r,j-l);
            dp=ndp;
        }
        for(int i=1;i<=sz;i++) g[d]=add(g[d],dp[i]);
    }
    for(int i=m;i>=1;i--)
    {
        for(int j=2*i;j<=m;j+=i) g[i]=sub(g[i],g[j]);
    }
    cout << g[1] << "\n";
    return 0;
}