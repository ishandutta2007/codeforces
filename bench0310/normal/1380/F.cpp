#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

array<ll,2> operator+(const array<ll,2> &a,const array<ll,2> &b)
{
    return {(a[0]+b[0])%mod,(a[1]+b[1])%mod};
}

array<ll,2> operator*(const ll &a,const array<ll,2> &b)
{
    return {(a*b[0])%mod,(a*b[1])%mod};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    s="$"+s;
    s+="0";
    vector<int> c(n+2,0);
    for(int i=1;i<=n+1;i++) c[i]=(s[i]-'0');
    const int sz=500;
    auto bucket=[&](int i)->int{return (n-i)/sz+1;};
    int mx=bucket(1);
    vector<int> l(mx+1,0);
    vector<int> r(mx+1,0);
    for(int i=1;i<=mx;i++) r[i]=(n-(i-1)*sz);
    for(int i=1;i<=mx;i++) l[i]=max(1,n-i*sz+1);
    vector<array<ll,2>> dp(n+2,{0,0});
    auto eval=[&](int id,int pos)->array<ll,2>
    {
        if(pos<=n&&bucket(pos)==id) return dp[pos];
        else if(pos==r[id]+1) return {1,0};
        else if(pos==r[id]+2) return {0,1};
        assert(0);
        return {0,0};
    };
    auto ini=[&](int id)
    {
        array<ll,2> b=eval(id,r[id]+2);
        for(int i=r[id];i>=l[id];i--)
        {
            array<ll,2> a=eval(id,i+1);
            dp[i]=((c[i]+1)*a);
            if(c[i]==1) dp[i]=dp[i]+((19-(10*c[i]+c[i+1]))*b);
            b=a;
        }
    };
    vector<array<ll,2>> tmp(mx+1,{0,0});
    tmp[0]={1,0};
    for(int i=1;i<=mx;i++)
    {
        ini(i);
        array<ll,2> &a=tmp[i-1];
        tmp[i]={(dp[l[i]][0]*a[0]+dp[l[i]][1]*a[1])%mod,(dp[l[i]+1][0]*a[0]+dp[l[i]+1][1]*a[1])%mod};
    }
    while(m--)
    {
        int x,d;
        cin >> x >> d;
        c[x]=d;
        ini(bucket(x));
        if(x==l[bucket(x)]&&bucket(x)<mx&&c[x-1]==1) ini(bucket(x)+1);;
        for(int i=bucket(x);i<=mx;i++)
        {
            array<ll,2> &a=tmp[i-1];
            tmp[i]={(dp[l[i]][0]*a[0]+dp[l[i]][1]*a[1])%mod,(dp[l[i]+1][0]*a[0]+dp[l[i]+1][1]*a[1])%mod};
        }
        cout << tmp[mx][0] << "\n";
    }
    return 0;
}