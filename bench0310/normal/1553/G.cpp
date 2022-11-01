#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000001;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    auto primes=[&](int x)->vector<int>
    {
        vector<int> v;
        while(x>1)
        {
            int p=sieve[x];
            v.push_back(p);
            while((x%p)==0) x/=p;
        }
        return v;
    };
    vector<int> p(N+1,0);
    vector<int> sz(N+1,1);
    for(int i=0;i<=N;i++) p[i]=i;
    function<int(int)> find_set=[&](int a)->int
    {
        if(a==p[a]) return a;
        else return p[a]=find_set(p[a]);
    };
    auto merge_sets=[&](int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    };
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        vector<int> v=primes(a[i]);
        for(int x:v) for(int y:v) merge_sets(x,y);
    }
    set<array<int,2>> edges;
    for(int i=1;i<=n;i++)
    {
        vector<int> u=primes(a[i]);
        vector<int> v=primes(a[i]+1);
        for(int x:u) for(int y:v) edges.insert({find_set(x),find_set(y)});
        for(int x:v) for(int y:u) edges.insert({find_set(x),find_set(y)});
        for(int x:v) for(int y:v) edges.insert({find_set(x),find_set(y)});
    }
    while(q--)
    {
        int s,t;
        cin >> s >> t;
        vector<int> one=primes(a[s]);
        vector<int> two=primes(a[t]);
        int res=2;
        for(int x:one)
        {
            for(int y:two)
            {
                if(find_set(x)==find_set(y)) res=min(res,0);
                if(edges.find({find_set(x),find_set(y)})!=edges.end()) res=min(res,1);
            }
        }
        cout << res << "\n";
    }
    return 0;
}