#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,mod;
    cin >> n >> mod;
    auto add=[&](int a,int b)->int{return a+b-(a+b>=mod?mod:0);};
    auto sub=[&](int a,int b)->int{return a-b+(a-b<0?mod:0);};
    vector<int> dp(n+2,0);
    vector<int> sum(n+2,0);
    sum[1]=1;
    sum[2]=mod-1;
    auto inc=[&](int l,int r,int x)
    {
        r=min(r,n);
        sum[l]=add(sum[l],x);
        sum[r+1]=sub(sum[r+1],x);
    };
    for(int i=1;i<=n;i++)
    {
        dp[i]=add(dp[i-1],sum[i]);
        inc(i+1,n,dp[i]);
        for(int x=2;i*x<=n;x++) inc(x*i,x*(i+1)-1,dp[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}