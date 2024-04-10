#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sieve(n+1,0);
    vector<ll> x(n+1,0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=1;i<=n;i++)
    {
        sieve[i]=i;
        x[i]=rng();
    }
    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=n;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<ll> f(n+1,0);
    map<ll,int> m;
    ll y=0;
    for(int i=1;i<=n;i++)
    {
        int a=i;
        f[i]=f[i-1];
        while(a>1)
        {
            int p=sieve[a];
            f[i]^=x[p];
            a/=p;
        }
        m[f[i]]=i;
        y^=f[i];
    }
    auto out=[&](vector<int> bad)
    {
        cout << n-bad.size() << "\n";
        for(int i=1;i<=n;i++) if(ranges::find(bad,i)==bad.end()) cout << i << " ";
        cout << "\n";
        exit(0);
    };
    if(y==0) out({});
    for(int i=1;i<=n;i++) if(f[i]==y) out({i});
    for(int i=1;i<=n;i++) if(m.contains(y^f[i])) out({i,m[y^f[i]]});
    out({2,(n-1)/2,n});
    return 0;
}