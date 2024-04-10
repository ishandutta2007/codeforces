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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int cant(vector<int> per,vector<pii> xs)
{
    int res=0;
    for(auto y : xs)
        if(y.s%3==per[y.f%3])
            res++;
    return res;
}

vector<pii> pcant(vector<int> per,vector<pii> xs)
{
    vector<pii> res;
    for(auto y : xs)
        if(y.s%3==per[y.f%3])
            res.push_back(y);
    return res;
}

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
        vector<string> ss(n);
        for(int i=0;i<n;i++)
            cin >> ss[i];
        vector<pii> xs;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ss[i][j]=='X')
                    xs.push_back(pii(i,j));
        vector<pii> xo;
        vector<int> per;
        per.push_back(0);
        per.push_back(1);
        per.push_back(2);
        int x=cant(per,xs);
        if(x*3<=xs.size())
            xo=pcant(per,xs);
        else
        {
            while(next_permutation(all(per)))
            {
                int x=cant(per,xs);
                if(x*3<=xs.size())
                {
                    xo=pcant(per,xs);
                    break;
                }
            }
        }

        vector<pii> os;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ss[i][j]=='O')
                    os.push_back(pii(i,j));
        per.clear();
        per.push_back(0);
        per.push_back(1);
        per.push_back(2);
        vector<pii> ox;
        x=cant(per,os);
        if(x*3<=xs.size() && !cant(per,xo))
            ox=pcant(per,os);
        else
        {
            while(next_permutation(all(per)))
            {
                int x=cant(per,os);
                if(x*3<=xs.size() && !cant(per,xo))
                {
                    ox=pcant(per,os);
                    break;
                }
            }
        }

        for(auto y : xo)
            ss[y.f][y.s]='O';
        for(auto y : ox)
            ss[y.f][y.s]='X';
        for(int i=0;i<n;i++)
            db(ss[i])
    }

    return 0;
}