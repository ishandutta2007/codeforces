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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2.5e2+5)

int r[MAXN],c[MAXN];
int a[MAXN][MAXN];
int res[MAXN][MAXN];

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
            r[i]=max(r[i],a[i][j]);
            c[j]=max(c[j],a[i][j]);
        }

    vector<int> rs;
    vector<int> cs;
    vector<int> bs;
    vector<int> faltan;
    vector<pii> ts;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int v=0;
            if(a[i][j]==r[i])
                v++;
            if(a[i][j]==c[j])
                v+=2;
            if(v==1)
                rs.push_back(a[i][j]);
            if(v==2)
                cs.push_back(a[i][j]);
            if(v==3)
                bs.push_back(a[i][j]);
            if(!v)
                faltan.push_back(a[i][j]);
            else
                ts.push_back(pii(a[i][j],v));
        }

    sort(all(ts));
    sort(all(rs));
    sort(all(cs));
    sort(all(bs));
    sort(allr(faltan));

    for(int i=0;i<bs.size();i++)
        res[n-i-1][m-i-1]=bs[i];
    for(int i=0;i<rs.size();i++)
        res[i][m-bs.size()]=rs[i];
    for(int i=0;i<cs.size();i++)
        res[n-bs.size()][i]=cs[i];

    int cr=0;
    int cc=0;
    int cb=0;
    for(int i=0;i<ts.size();i++)
    {
        int ty=ts[i].s;
//        cout << ts[i].f << ' ' << ts[i].s << '\n';
//        db(faltan.size())
        if(ty==1)
        {
            for(int i=0;i<m-bs.size();i++)
            {
                if(res[cr][i])
                    continue;
                res[cr][i]=faltan.back();
                faltan.pop_back();
            }
            for(int i=m-1;i>m-bs.size();i--)
            {
                if(res[cr][i])
                    continue;
                res[cr][i]=faltan.back();
                faltan.pop_back();
            }
            cr++;
        }
        if(ty==2)
        {
            for(int i=0;i<n-bs.size();i++)
            {
                if(res[i][cc])
                    continue;
                res[i][cc]=faltan.back();
                faltan.pop_back();
            }
            for(int i=n-1;i>n-bs.size();i--)
            {
                if(res[i][cc])
                    continue;
                res[i][cc]=faltan.back();
                faltan.pop_back();
            }
            cc++;
        }
        if(ty==3)
        {
            for(int i=0;i<m-cb-1;i++)
            {
                if(res[n-cb-1][i])
                    continue;
                res[n-cb-1][i]=faltan.back();
                faltan.pop_back();
            }
            for(int i=0;i<n-cb-1;i++)
            {
                if(res[i][m-cb-1])
                    continue;
                res[i][m-cb-1]=faltan.back();
                faltan.pop_back();
            }
            cb++;
        }
    }

    for(int i=0;i<n;i++,cout << '\n')
        for(int j=0;j<m;j++)
            cout << res[i][j] << ' ';

    return 0;
}
/**
3 3
3 5 6
1 7 9
4 8 2
**/