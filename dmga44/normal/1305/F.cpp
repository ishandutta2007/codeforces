#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1000005

ll a[MAXN];
vector<ll> primes;
bool c[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!c[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<MAXN;j+=i)
                c[j]=1;
        }
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    srand(time(0));

    criba();

    int n;
    cin >> n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
        v.push_back(a[i]+1);
        if(a[i]>1)
            v.push_back(a[i]-1);
    }

    ll tam=v.size();
    vector<ll> ts;
    int rep=100;
    for(int i=0;i<rep;i++)
    {
        ll r1=rand();
        ll r2=rand();
        ll r3=rand();
        ll rrr=(r1*r2)%tam;
        rrr=(rrr*r3)%tam;
        ts.push_back(v[rrr]);
    }

    set<ll> prims;
    for(auto y : ts)
    {
        for(auto p : primes)
        {
            if(y%p==0)
                prims.insert(p);
            while(y%p==0)
                y/=p;
            if(y==1)
                break;
        }
        if(y!=1)
            prims.insert(y);
    }

    ll res=1e6;
    for(auto p : prims)
    {
        ll sum=0;
        for(int j=0;j<n;j++)
        {
            ll mmm=a[j]%p;
            if(mmm==0)
                mmm=p;
            if(a[j]<p)
                sum+=(p-mmm);
            else
                sum+=min(p-mmm,mmm);
        }
        res=min(sum,res);
    }
    db(res)

    return 0;
}