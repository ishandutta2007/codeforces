#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,lim,k;
    cin >> n >> lim >> k;
    vector<array<int,2>> v(n+1,{0,0});
    auto swap_bits=[&](int a,int i,int j)
    {
        if(((a>>i)&1)!=((a>>j)&1)) a^=((1<<i)^(1<<j));
        return a;
    };
    auto go=[&](string s,vector<int> &dp,auto opt)
    {
        ranges::reverse(s);
        int x=stoi(s,0,2);
        vector<int> pinv(k);
        for(int i=0;i<k;i++) pinv[i]=i;
        dp[x]=opt(dp[x],0);
        for(int i=1;i<=n;i++)
        {
            auto [a,b]=v[i];
            x=swap_bits(x,pinv[a],pinv[b]);
            swap(pinv[a],pinv[b]);
            dp[x]=opt(dp[x],i);
        }
        for(int m=(1<<k)-1;m>=0;m--)
        {
            for(int i=0;i<k;i++) if((m&(1<<i))==0) dp[m]=opt(dp[m],dp[m^(1<<i)]);
        }
    };
    string s,t;
    cin >> s >> t;
    for(int i=1;i<=n;i++)
    {
        auto &[a,b]=v[i];
        cin >> a >> b;
        a--; b--;
    }
    vector<int> one(1<<k,n+1);
    vector<int> two(1<<k,-1);
    go(s,one,[](int a,int b){return min(a,b);});
    go(t,two,[](int a,int b){return max(a,b);});
    int c=ranges::count(t,'0')-ranges::count(s,'1');
    array<int,3> res={-1,0,0};
    for(int m=0;m<(1<<k);m++)
    {
        if(one[m]!=n+1&&two[m]!=-1&&two[m]-one[m]>=lim) res=max(res,{2*popcount(uint32_t(m))+c,one[m]+1,two[m]});
    }
    cout << res[0] << "\n";
    cout << res[1] << " " << res[2] << "\n";
    return 0;
}