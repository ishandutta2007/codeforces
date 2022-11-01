#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int N=20000000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    vector<int> primes;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        primes.push_back(i);
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<ll> dp(N+1,0);
    vector<ll> cnt(N+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        vector<array<int,2>> f;
        while(a>1)
        {
            int p=sieve[a];
            int c=0;
            while(sieve[a]==p)
            {
                c++;
                a/=p;
            }
            f.push_back({p,c});
        }
        int sz=f.size();
        function<void(int,int)> gen=[&](int id,int r)
        {
            if(id==sz) cnt[r]++;
            else
            {
                gen(id+1,r);
                auto [p,c]=f[id];
                for(int j=1;j<=c;j++)
                {
                    r*=p;
                    gen(id+1,r);
                }
            }
        };
        gen(0,1);
    }
    ll res=0;
    for(int i=N;i>=1;i--)
    {
        dp[i]=i*cnt[i];
        for(int p:primes)
        {
            int j=p*i;
            if(j<=N) dp[i]=max(dp[i],dp[j]+i*(cnt[i]-cnt[j]));
            else break;
        }
        res=max(res,dp[i]);
    }
    cout << res << "\n";
    return 0;
}