#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int n,q;
    cin >> n >> q;
    map<int,int> m[n+1];
    auto f=[&](int a)->vector<array<int,2>>
    {
        vector<array<int,2>> v;
        while(a>1)
        {
            int p=sieve[a];
            v.push_back({p,0});
            while(sieve[a]==p)
            {
                v.back()[1]++;
                a/=p;
            }
        }
        return v;
    };
    ll res=1;
    const ll mod=1000000007;
    auto fpow=[&](ll b,ll e)->ll
    {
        ll r=1;
        while(e)
        {
            if(e&1) r=(r*b)%mod;
            b=(b*b)%mod;
            e/=2;
        }
        return r;
    };
    auto inv=[&](ll a)->ll
    {
        return fpow(a,mod-2);
    };
    multiset<int> pw[N+1];
    auto mul=[&](int i,int x)
    {
        vector<array<int,2>> v=f(x);
        for(auto [p,e]:v)
        {
            if(m[i].find(p)==m[i].end())
            {
                m[i][p]=e;
                pw[p].insert(e);
                if((int)pw[p].size()==n) res=(res*fpow(p,*pw[p].begin()))%mod;
            }
            else
            {
                if((int)pw[p].size()==n) res=(res*inv(fpow(p,*pw[p].begin())))%mod;
                pw[p].erase(pw[p].find(m[i][p]));
                m[i][p]+=e;
                pw[p].insert(m[i][p]);
                if((int)pw[p].size()==n) res=(res*fpow(p,*pw[p].begin()))%mod;
            }
        }
    };
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        mul(i,a);
    }
    while(q--)
    {
        int i,x;
        cin >> i >> x;
        mul(i,x);
        cout << res << "\n";
    }
    return 0;
}