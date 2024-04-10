#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int mod;
    cin >> n >> mod;
    auto add=[&](int a,int b)->int{return (a+b<mod?a+b:a+b-mod);};
    auto sub=[&](int a,int b)->int{return (a-b>=0?a-b:a-b+mod);};
    auto mul=[&](int a,int b)->int{return (ll(a)*b)%mod;};
    vector c(n+1,vector(n+1,int(0)));
    for(int i=0;i<=n;i++) c[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=add(c[i-1][j],c[i-1][j-1]);
    vector<int> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=mul(f[i-1],i);
    int res=0;
    auto inv=[&](int i)->int{return (i*(i-1)/2);};
    int lim=inv(n);
    vector<int> dp(2*lim+1,0); //number of (p,q) of length len with inv(p)-inv(q)==j
    dp[lim]=1;
    for(int len=1;len<=n;len++)
    {
        vector<int> sum(2*lim+1,0);
        for(int j=2*lim;j>=0;j--) sum[j]=add((j<2*lim?sum[j+1]:0),dp[j]);
        int match=n-len;
        int opt=mul(c[n][match],f[match]);
        int t=0;
        for(int d=1;d<=len-1;d++)
        {
            int cnt=len-d;
            t=add(t,mul(cnt,sum[d+1+lim]));
        }
        res=add(res,mul(opt,t));
        for(int j=0;j<=2*lim;j++) sum[j]=add((j>0?sum[j-1]:0),dp[j]);
        auto s=[&](int l,int r)->int
        {
            l+=lim; r+=lim;
            l=max(l,0);
            r=min(r,2*lim);
            return sub(sum[r],(l>0?sum[l-1]:0));
        };
        vector<int> ndp(2*lim+1,0);
        int mx=inv(len);
        ndp[-mx+lim]=1;
        for(int j=-mx+1;j<=mx;j++)
        {
            int &now=ndp[j+lim];
            now=ndp[j-1+lim];
            now=sub(now,s(j-len,j-1));
            now=add(now,s(j,j+len-1));
        }
        dp=ndp;
    }
    cout << res << "\n";
    return 0;
}