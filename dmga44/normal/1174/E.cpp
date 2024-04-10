#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1000005
#define mod ((ll)(1e9+7))

ll f[MAXN],p[MAXN];
map<pii,ll> m;
vector<int> dp;

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=max(p[j],p[j/i]+1);
}

ll gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    f[0]=1;
    for(ll i=1;i<MAXN;i++)
        f[i]=(f[i-1]*i)%mod;

    dp.push_back(2);
    dp.push_back(3);
    dp.push_back(5);
    int n;
    cin >> n;
    priority_queue<pii,vector<pii>,less<pii>> pq;
    int v=0;
    for(int i=2;i<=n;i++)
    {
        if(p[i]>v)
        {
            v=p[i];
            while(!pq.empty())
                pq.pop();
            pq.push(pii(n-1,i));
            m[pii(n-1,i)]=1;
        }
        else if(p[i]==v)
        {
            pq.push(pii(n-1,i));
            m[pii(n-1,i)]=1;
        }
    }

    ll res=0;
    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();

        int u=x.first;
        int v=x.second;
        if(u==1)
        {
            res=(res+m[x])%mod;
            continue;
        }
        ll w=n/v-(n-u);
        if(w)
        {
            if(!m[pii(u-1,v)])
                pq.push(pii(u-1,v));
            m[pii(u-1,v)]=(m[pii(u-1,v)]+m[x]*w)%mod;
        }
        for(auto y : dp)
        {
            if(v%y)
                continue;
            if(!m[pii(u-1,v/y)])
                pq.push(pii(u-1,v/y));
            ll ww=(n/(v/y))-(n-u)-w;
            m[pii(u-1,v/y)]=(m[pii(u-1,v/y)]+m[x]*ww)%mod;
        }
    }
    db(res)

    return 0;
}