#include <bits/stdc++.h>

using namespace std;

const int N=300000+5;
const int MOD=1000000007;

inline int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

inline int add(int a,int b)
{
    a+=b;
    if(a>=MOD) a-=MOD;
    if(a<0) a+=MOD;
    return a;
}

inline int expow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=mul(ans,a);
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

int fact[N];

inline int comb(int n,int k)
{
    if(0<=k && k<=n)
    {
        int x=fact[n];
        int y=mul(fact[k],fact[n-k]);
        return mul(x,expow(y,MOD-2));
    }
    return 0;
}

int n;
int cnt[N];
int dp[N];

int K;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0]=1;
    for(int i=1;i<N;i++) fact[i]=mul(fact[i-1],i);
    cin>>n;
    int all=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        all=__gcd(all,x);
        cnt[x]=1;
    }
    if(all!=1)
    {
        cout<<"-1\n";
        return 0;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=2*i;j<N;j+=i)
        {
            cnt[i]+=cnt[j];
        }
    }
    while(1)
    {
        K++;
        for(int i=N-1;i>=1;i--)
        {
            dp[i]=comb(cnt[i],K);
            for(int j=2*i;j<N;j+=i)
            {
                dp[i]=add(dp[i],-dp[j]);
            }
        }
        if(dp[1]==0) continue;
        cout<<K<<"\n";
        break;
    }
    return 0;

}