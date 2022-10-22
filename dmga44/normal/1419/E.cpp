#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pii> fac;
        set<int> divs;
        int nn=n;
        for(int i=1;i<=32000;i++)
        {
            if(n%i==0)
            {
                divs.insert(i);
                if(n/i!=i)
                    divs.insert(n/i);
            }

            if(i==1)
                continue;
            int e=0;
            while(nn%i==0)
            {
                nn/=i;
                e++;
            }
            if(e)
                fac.push_back(pii(i,e));
        }
//        db("xxx")
        if(nn!=1)
            fac.push_back(pii(nn,1));

        int fs=fac.size();
        vector<int> ps[2*fs];
        map<pii,vector<int> > mp;
        map<pii,int> mc;
        for(int i=0;i<fs;i++)
        {
            mp[pii(fac[i].f,fac[(i+1)%fs].f)].push_back(2*i+1);
            mp[pii(fac[(i+1)%fs].f,fac[i].f)].push_back(2*i+1);
            mp[pii(fac[i].f,fac[i].f)].push_back(2*i);
            int tp=1;
            for(int j=1;j<=fac[i].s;j++)
            {
                tp*=fac[i].f;
                ps[2*i].push_back(tp);
            }
        }

        for(auto y : divs)
        {
            vector<int> ds;
            for(auto d : fac)
                if(y%d.f==0)
                    ds.push_back(d.f);
            if(ds.size()<2)
               continue;
            pii x=pii(ds[0],ds[1]);
            if(mp[x].size())
            {
                int p=mc[x];
                ps[mp[x][p%mp[x].size()]].push_back(y);
                mc[x]++;
            }
            else
            {
                pii x=pii(ds[0],ds[0]);
                int p=mc[x];
                ps[mp[x][p%mp[x].size()]].push_back(y);
                mc[x]++;
            }
        }

        vector<int> res;
        for(int i=0;i<2*fs;i++)
            for(auto y : ps[i])
                res.push_back(y);
        ll rc=0;
        for(int i=0;i<res.size();i++)
            if(__gcd(res[i],res[(i+1)%res.size()])==1)
                rc++;

        for(int i=0;i<res.size();i++)
            cout << res[i] << ' ';
        cout << '\n';
        db(rc)
    }

    return 0;
}
/**
3
6
4
30

10
4
5
6
7
8
9
10
11
12
13
**/