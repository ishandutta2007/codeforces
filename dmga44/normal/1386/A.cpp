#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

map<ll,int> mm;
ll c;
ll pos;
int cont;

int ask(ll x)
{
    cont++;
    mm[x]++;
    cout << "? " << x << '\n';
    cout.flush();
    int res;
    cin >> res;
//    res=(abs(x-pos)>=c);
    return res;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
//    for(int i=2;i<=64;i++)
//    for(int j=1;j<=i;j++)
    {

        ll n;
//        n=i;
//        c=j;
        cin >> n;
//        cin >> c;
        n--;
        vector<ll> cachos;
        ll nn=n;
        while(nn)
        {
            cachos.push_back((nn>>1)+(nn&1));
            nn>>=1;
        }

        ll ini=0;
        for(int i=1;i<cachos.size();i+=2)
            ini+=cachos[i];
        ini++;

        ask(ini);
        ll res=0;
        pos=ini;
        ll ty=1;
        for(int i=0;i<cachos.size();i++)
        {
            ll po=cachos[i];
            ll p=pos+(ty)*(res+po);
            if(p<=0 || p>n+1)
            {
                ty=-ty;
                p=pos+(ty)*(res+po);
            }
//            if(p<=0 || p>n+1)
//                cout << i << ' ' << j << '\n';
            ll v=ask(p);
            ty=-ty;
            pos=p;
            if(!v)
                res+=po;
            else
            {
                while(i+1<cachos.size() && cachos[i]==cachos[i+1])
                    i++;
            }
        }

        cont=0;
        int ma=0;
        for(auto y : mm)
            ma=max(ma,y.s);
        mm.clear();
        res++;
        cout << "= " << res << '\n';
        cout.flush();
//        if(ma>1 || res!=c || cont>64)
//            cout << i << ' ' << j << '\n';
    }

    return 0;
}