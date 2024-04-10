#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 1000005
#define mod 1000000007

bool p[MAXN];
vector<ll> primes;

void criba()
{
    for(int i=4;i<MAXN;i+=2)
        p[i]=1;
    for(int i=3;i*i<MAXN;i+=2)
        if(!p[i])
            for(int j=i*i;j<MAXN;j+=2*i)
                p[j]=1;
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x);
    if(e&1)
        x=(x*b);
    return x;
}

vector<pii> fc(ll n)
{
    vector<pii> res;
    for(ll i=0;i<primes.size() && n>=primes[i];i++)
    {
        ll x=primes[i];
        if(n%x)
            continue;
        ll e=0;
        while(n%x==0)
        {
            e++;
            n/=x;
        }
        res.push_back(pii(x,e));
    }
    if(n!=1)
        res.push_back(pii(n,1));
    return res;
}

ll f(ll n)
{
    vector<pii> fac=fc(n);
    ll res=1;
    for(auto y : fac)
        res*=((y.first-1ll)*qp(y.first,y.second-1ll));
    return res;
}

ll g(ll n)
{
    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            primes.push_back(i);

    ll n,k;
    cin >> n >> k;
    vector<bool> v;
    v.push_back(0);
    while(v.size()<MAXN && v.size()<=k)
        v.push_back(v.size()&1);

    ll p=0;
    while(p<v.size())
    {
        if(!v[p])
            n=g(n);
        else
            n=f(n);
        p++;
    }
    db(n%mod)

    return 0;
}