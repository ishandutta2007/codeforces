#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

vector<int> vs((int)2e6);
int pp[(int)(2e6)];

pii solve(ll h,ll a,ll x,ll y,ll m)
{
    ll cycle;
    int pos=-1;
    vs[0]=h;
    for(int i=0;i<m;i++)
        pp[i]=0;
    for(int i=1;i<2e6;i++)
        vs[i]=(vs[i-1]*x+y)%m;
    for(int i=1e6;i<2e6;i++)
    {
        if(vs[i]==a)
            pos=i;
        if(pp[vs[i]])
            cycle=i-pp[vs[i]];
        pp[vs[i]]=i;
    }
    return pii(pos,cycle);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m;
    cin >> m;
    ll h1,a1,x1,y1;
    cin >> h1 >> a1 >> x1 >> y1;
    ll h2,a2,x2,y2;
    cin >> h2 >> a2 >> x2 >> y2;
    ll v1=h1;
    ll v2=h2;
    for(int i=0;i<2e6;i++)
    {
        v1=(v1*x1+y1)%m;
        v2=(v2*x2+y2)%m;
        if(v1==a1 && v2==a2)
        {
            db(i+1)
            return 0;
        }
    }

    pii f1=solve(h1,a1,x1,y1,m);
    pii f2=solve(h2,a2,x2,y2,m);

    if(f1.f==-1 || f2.f==-1)
        db(-1)
    else
    {
        for(ll xxx=0;xxx<2e6;xxx++)
            if((f1.first+f1.s*xxx)%f2.s==(f2.f%f2.s))
            {
                db(f1.first+f1.s*xxx)
                return 0;
            }
        db(-1)
    }

    return 0;
}
/**
5
4 2
1 1
0 1
2 3
1023
1 2
1 0
1 2
1 1
**/