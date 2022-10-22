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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)
#define MAXP (ll)(1e2+5)

ll d[MAXN];
ll dp[MAXP][MAXN];

ll cross(point a, point b) { return imag(conj(a) * b); } ///a_x*b_y-b_x*a_y

ll dot(point a, point b) { return real(conj(a) * b); } /// a_x*b_x+a_y*b_y

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

struct hull : vector<point>
{
    int pos;
    hull() : pos(0) {}
    void add_point(point p)
    {
        for (int s = size(); s > 1; --s)
            if (area2(at(s - 2), at(s - 1), p) < 0) break;
            else pop_back();
        push_back(p);
        pos=min(pos,(int)size()-1);
    }

    ll max_dot(point p)
    {
        while (pos<size()-1 && dot(at(pos),p)<dot(at(pos+1),p))
            pos++;

        return dot(at(pos), p);
    }
};

hull cht[MAXP];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,p;
    cin >> n >> m >> p;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin >> x;
        d[i+1]=d[i]+x;
    }

    vector<ll> ps;
    for(int i=0;i<m;i++)
    {
        int u,t;
        cin >> u >> t;
        u--;
        t-=d[u];
        ps.push_back(t);
    }

    sort(all(ps));

//    for(int i=0;i<m;i++)
//        cout << ps[i] << ' ';
//    cout << '\n';

    for(int i=0;i<=m;i++)
        for(int j=0;j<=p;j++)
            dp[j][i]=oo;

    cht[0].add_point(point(0,0));
    ll cj=0;
    ll sj=0;
    for(int i=0;i<m;i++)
    {
        cj++;
        sj+=ps[i];
//        db("")
//        db(i)
//        cout << cj << ' ' << sj << '\n';
        for(int k=0;k<min(i+1,(int)p);k++)
        {
            ll w=cht[k].max_dot(point(ps[i],1));
            w*=-1;
            w+=(cj*ps[i]-sj);
            dp[k+1][i+1]=w;
//            cout << k+1 << ' ' << dp[k+1][i+1] << '\n';
            cht[k+1].add_point(point(cj,-(sj+w)));
        }
    }

    ll res=oo;
    for(int i=0;i<p;i++)
        res=min(res,dp[i+1][m]);
    db(res)

    return 0;
}
/**
4 6 2
1 3 5
1 0
2 1
4 9
1 10
2 10
3 12
**/