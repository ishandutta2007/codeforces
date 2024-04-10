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
typedef double ld;
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
const ll mod=(ll)(1ll<<60);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<10)

vector<int> res(181,1e4);

double dot(point a, point b) { return real(conj(a) * b); }

void solve(vector<point> ps)
{
    int n=ps.size();
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            point v1=ps[i]-ps[0];
            point v2=ps[j]-ps[0];
            ld cang=dot(v1,v2)/(abs(v1)*abs(v2));
            ld ang=acos(cang);
            ll kk=((ang+1e-9)/pi)*180;
            if(abs((kk*(pi/180))-ang)<eps)
                res[kk]=min(res[kk],n);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=3;i<=360;i++)
    {
        if(360%i)
            continue;
        ld ang=(2*pi)/(ld)(i);
        vector<point> ps;
        for(int j=0;j<i;j++)
            ps.push_back(point(cos(j*ang),sin(j*ang)));
        solve(ps);
    }

    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        db(res[x])
    }

    return 0;
}