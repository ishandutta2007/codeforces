#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    vector<int> sieve(N+1);
    for(int i=1;i<=N;i++) sieve[i]=i;
    vector<int> phi(N+1,1);
    for(int i=2;i<=N;i++)
    {
        int p=sieve[i];
        if(p==i) phi[i]=i-1;
        else if((i/p)%p) phi[i]=phi[p]*phi[i/p];
        else phi[i]=p*phi[i/p];
        if(p==i&&i<=N/i) for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<ll> p(N+1,0);
    for(int i=1;i<=N;i++) p[i]=p[i-1]+phi[i];
    auto c=[&](int l,int r)
    {
        ll t=0;
        while(l<=r)
        {
            int lim=(r/(r/l));
            t+=(p[r/l]*(lim-l+1));
            l=lim+1;
        }
        return t;
    };
    const int K=16;
    const ll inf=(1ll<<60);
    vector dp(K+1,vector(N+1,ll(inf/2)));
    dp[0][0]=0;
    int k=1;
    function<void(int,int,int,int)> go=[&](int l,int r,int optl,int optr)
    {
        if(l>r) return;
        int m=(l+r)/2;
        array<ll,2> best={inf,0};
        ll t=c(min(m,optr),m);
        for(int i=min(m,optr);i>=optl;i--)
        {
            best=min(best,{dp[k-1][i-1]+t,i});
            if(i>1) t+=p[m/(i-1)];
        }
        dp[k][m]=best[0];
        go(l,m-1,optl,best[1]);
        go(m+1,r,best[1],optr);
        
    };
    for(;k<=K;k++) go(1,N,1,N);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n >> k;
        if(k<=K) cout << dp[k][n] << "\n";
        else cout << n << "\n";
    }
    return 0;
}