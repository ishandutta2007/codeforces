#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const int N=1000000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto fpow=[&](int b,int e)->int
    {
        int r=1;
        while(e)
        {
            if(e&1) r*=b;
            b*=b;
            e/=2;
        }
        return r;
    };
    vector<int> val(20,0);
    for(int i=1;i<=19;i++)
    {
        val[i]=0;
        for(int j=1;j<(1<<i);j++)
        {
            ll l=1;
            int mn=0;
            for(int k=1;k<=i;k++) if(j&(1<<(k-1))) {l=lcm(l,k); if(mn==0)mn=k;}
            if(popcount(uint32_t(j))&1) val[i]+=(m*mn/l);
            else val[i]-=(m*mn/l);
        }
    }
    ll res=1;
    vector<int> cnt(n+1,0);
    for(int i=2;i<=n;i++)
    {
        int a=i;
        int g=0;
        vector<array<int,2>> v;
        while(a>1)
        {
            int p=sieve[a];
            int c=0;
            while((a%p)==0)
            {
                c++;
                a/=p;
            }
            g=gcd(g,c);
            v.push_back({p,c});
        }
        ll o=1;
        for(auto [p,c]:v) o*=fpow(p,c/g);
        ll t=1;
        for(int j=1;j<g;j++)
        {
            t*=o;
            cnt[i]-=cnt[t];
        }
        cnt[i]+=val[g];
        res+=cnt[i];
    }
    cout << res << "\n";
    return 0;
}