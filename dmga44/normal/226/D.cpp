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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e2+5)

bool res[2][MAXN];
int a[MAXN][MAXN];
int rs[MAXN];
int cs[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            rs[i]+=a[i][j];
            cs[j]+=a[i][j];
        }
//    for(int i=0;i<n;i++)
//        db(rs[i])
//    for(int i=0;i<m;i++)
//        db(cs[i])

    while(1)
    {
        pii hay=pii(-1,-1);
        for(int i=0;i<n && hay==pii(-1,-1);i++)
        {
//            db(rs[i])
            if(rs[i]<0)
                hay=pii(0,i);
        }
//        cout << hay.f << ' ' << hay.s << '\n';
        for(int i=0;i<m && hay==pii(-1,-1);i++)
            if(cs[i]<0)
                hay=pii(1,i);
        if(hay==pii(-1,-1))
            break;
//        db("xxx")
        res[hay.f][hay.s]^=1;
        if(!hay.first)
        {
            int i=hay.s;
            rs[i]*=-1;
            for(int j=0;j<m;j++)
            {
                cs[j]-=(2*a[i][j]);
                a[i][j]*=-1;
            }
        }
        else
        {
            int i=hay.s;
            cs[i]*=-1;
            for(int j=0;j<n;j++)
            {
                rs[j]-=(2*a[j][i]);
                a[j][i]*=-1;
            }
        }
    }

    vector<int> r;
    vector<int> c;
    for(int i=0;i<n;i++)
        if(res[0][i])
            r.push_back(i);
    for(int i=0;i<m;i++)
        if(res[1][i])
            c.push_back(i);
    cout << r.size();
    for(auto y : r)
        cout << ' ' << y+1;
    cout << '\n';
    cout << c.size();
    for(auto y : c)
        cout << ' ' << y+1;
    cout << '\n';

    return 0;
}
/**
4 1
-1
-1
-1
-1
**/