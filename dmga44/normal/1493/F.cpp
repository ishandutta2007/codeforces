#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int ask(int h,int w,int i1,int j1,int i2,int j2,int flag)
{
    if(!flag)
        cout << "? " << h << ' ' << w << ' ' << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << '\n';
    else
        cout << "? " << w << ' ' << h << ' ' << j1 << ' ' << i1 << ' ' << j2 << ' ' << i2 << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;
}

bool tr(int n,int m,int f,int p)
{
    if(p==2)
        return ask(n/2,m,1,1,1+n/2,1,f);
    int x=p/2;
    int f1=ask((n/p)*x,m,1,1,1+(n/p)*x,1,f);
    if(f1)
        return ask((n/p)*x,m,1,1,n-((n/p)*x)+1,1,f);
    return 0;
}

int aux(int n,int m,int f)
{
    int act=n;
    vector<int> primes;
    int nn=n;
    for(int i=2;i<=n;i++)
    {
        if(!(nn%i))
        {
            primes.push_back(i);
            while(nn%i==0)
                nn/=i;
        }
    }
//    db(primes.size())

    for(int i=0;i<primes.size();i++)
        while((act%primes[i]==0) && tr(act,m,f,primes[i]))
            act/=primes[i];
    return act;
}

int solve(int n,int m)
{
    int szn=aux(n,m,0);
    int szm=aux(m,n,1);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i%szn==0 && j%szm==0 && n%i==0 && m%j==0)
                res++;
    return res;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int x=solve(n,m);
    cout << "! " << x << '\n';
    cout.flush();

    return 0;
}