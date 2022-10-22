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
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<ld> up(vector<ld> &app,int l,int r,int p)
{
    vector<ld> ac(app.size()+1);
    for(int i=0;i<app.size();i++)
        ac[i+1]=ac[i]+app[i];
    ld p1=((100.0-(ld)p)/100.0);
    ld p2=p1*(1.0/(ld)(r-l+1));
    vector<ld> res(app.size());
    ld sum=0;
    for(int i=1;i<app.size();i++)
    {
        int li=i+l;
        int ri=i+r;
        res[i]+=(1.0-p1)*app[i];
        if(li<app.size())
        {
            ri=min(ri,(int)app.size()-1);
            ld sum=ac[ri+1]-ac[li];
            res[i]+=(sum*p2);
        }
        sum+=res[i];
    }
    res[0]=1.0-sum;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int hp1,t1,l1,r1,p1;
    cin >> hp1 >> t1 >> l1 >> r1 >> p1;
    int hp2,t2,l2,r2,p2;
    cin >> hp2 >> t2 >> l2 >> r2 >> p2;
    if(p1==100)
    {
        db(0)
        return 0;
    }
    if(p2==100)
    {
        db(1.0)
        return 0;
    }
    vector<ld> pl1(hp1+1);
    vector<ld> pl2(hp2+1);
    pl1[hp1]=1;
    pl2[hp2]=1;
    ld x1=0;
    for(int i=0;1;i++)
    {
        if(!(i%t1))
        {
            ld plini=pl2[0];
            pl2=up(pl2,l1,r1,p1);
            x1+=(pl2[0]-plini)*(1-pl1[0]);
        }
        if(!(i%t2))
        {
            ld plini=pl1[0];
            pl1=up(pl1,l2,r2,p2);
        }
//        db("")
//        db(i)
//        db("t1")
//        for(int j=0;j<=hp1;j++)
//            if(pl1[j])
//                cout << j << ' ' << pl1[j] << '\n';
//        db("t2")
//        for(int j=0;j<=hp2;j++)
//            if(pl2[j])
//                cout << j << ' ' << pl2[j] << '\n';

        if(fabs(1-pl1[0])<1e-6 || fabs(1-pl2[0])<1e-6)
            break;
    }

    cout.precision(10);
    cout<<fixed;
//    cout << 1-(pl1[0]/(pl1[0]+pl2[0])) << ' ' << pl1[0] << ' ' << pl2[0] << '\n';
//    db(pl2[0]/(pl2[0]+pl1[0]))
    db(x1)

    return 0;
}
/**
100 3 50 50 0
100 3 50 50 0
100 3 50 50 0
100 2 48 50 0
100 3 50 50 0
100 1 50 50 50
100 3 50 50 0
100 1 50 50 25
**/