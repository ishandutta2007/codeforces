#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=500000;
    vector<int> sieve(N+1,0);
    for(int i=1;i<=N;i++) sieve[i]=i;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto primes=[&](int a)->vector<int>
    {
        vector<int> p;
        while(a>1)
        {
            if(p.empty()||p.back()!=sieve[a]) p.push_back(sieve[a]);
            a/=sieve[a];
        }
        return p;
    };
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> cnt(N+1,0);
    vector<bool> v(n+1,0);
    ll res=0;
    ll in=0;
    while(q--)
    {
        int b;
        cin >> b;
        vector<int> p=primes(a[b]);
        vector<int> one,two;
        for(int i=1;i<(1<<p.size());i++)
        {
            int now=1;
            int c=0;
            for(int j=0;j<(int)p.size();j++)
            {
                if(i&(1<<j))
                {
                    now*=p[j];
                    c++;
                }
            }
            if(c&1) one.push_back(now);
            else two.push_back(now);
        }
        if(v[b]==0)
        {
            for(int x:one) res+=cnt[x];
            for(int x:two) res-=cnt[x];
            for(int x:one) cnt[x]++;
            for(int x:two) cnt[x]++;
            in++;
        }
        else
        {
            for(int x:one) cnt[x]--;
            for(int x:two) cnt[x]--;
            for(int x:one) res-=cnt[x];
            for(int x:two) res+=cnt[x];
            in--;
        }
        v[b]=!v[b];
        cout << (in*(in-1)/2)-res << "\n";
    }
    return 0;
}