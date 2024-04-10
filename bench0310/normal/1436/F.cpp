#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll fpow(ll b,ll e)
{
    if(e<0) return fpow(fpow(b,mod-2),-e);
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

void add(ll &a,ll b){a=(a+b)%mod;}
void mul(ll &a,ll b){a=(a*b)%mod;}

ll solve(vector<array<ll,2>> v)
{
    ll sz=0;
    ll one=0;
    ll sum=0;
    for(auto [a,f]:v)
    {
        sz+=f;
        add(sum,f*a);
        add(one,((f*a)%mod)*a);
    }
    if(sz==0) return 0;
    ll two=(sum*sum-one)%mod;
    if(two<0) two+=mod;
    ll x=fpow(2,sz-2);
    mul(x,(sz-1)%mod);
    mul(x,one);
    ll y=0;
    if(sz>=2)
    {
        y=fpow(2,sz-3);
        mul(y,sz%mod);
        mul(y,two);
    }
    return (x+y)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int m;
    cin >> m;
    vector<ll> f(N+1,0);
    for(int i=0;i<m;i++)
    {
        int a;
        cin >> a;
        cin >> f[a];
    }
    ll res=0;
    for(int i=1;i<=N;i++)
    {
        int c=0;
        int t=i;
        bool ok=1;
        while(t>1)
        {
            int now=sieve[t];
            int num=0;
            while((t%now)==0)
            {
                num++;
                t/=now;
            }
            ok&=(num<=1);
            c+=(num==1);
        }
        if(ok==0) continue;
        vector<array<ll,2>> v;
        for(int j=i;j<=N;j+=i) v.push_back({j,f[j]});
        if((c%2)==0) res=(res+solve(v))%mod;
        else res=(res-solve(v))%mod;
    }
    if(res<0) res+=mod;
    cout << res << "\n";
    return 0;
}