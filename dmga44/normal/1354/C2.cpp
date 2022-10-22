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
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define pi		3.14159265358979323846

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--)
    {
        ld n;
        cin >> n;
        ld ang=pi/n;
        ld a=sqrt(1.0/(2.0-2.0*cos(ang)));
        vector<point> base;
        for(int i=0;i<2*n;i++)
        {
            base.push_back(a*point(cos((ld)i*ang),sin((ld)i*ang)));
        }
        vector<pdi> vd;
        for(int a1=0;a1<100;a1++)
        {
            ld axx=((ld)(a1)*(2*pi))/(100.0*n);
            point p=point(cos(axx),sin(axx));
            ld ix=1000,iy=1000,ax=-1000,ay=-1000;
            for(int i=0;i<2*n;i++)
            {
                point pp=base[i]*p;
                ix=min(ix,pp.real());
                ax=max(ax,pp.real());
                iy=min(iy,pp.imag());
                ay=max(ay,pp.imag());
            }
            vd.push_back(pdi(max(ax-ix,ay-iy),a1));
        }

        pdi mii=pdi(1000,0);
        for(int i=0;i<100;i++)
            mii=min(vd[i],mii);
        ld res=1000;
        for(int i=(mii.second-1)*100;i<(mii.second+1)*100;i++)
        {
            ld axx=((ld)(i)*(2*pi))/(10000.0*n);
            point p=point(cos(axx),sin(axx));
            ld ix=1000,iy=1000,ax=-1000,ay=-1000;
            for(int i=0;i<2*n;i++)
            {
                point pp=base[i]*p;
                ix=min(ix,pp.real());
                ax=max(ax,pp.real());
                iy=min(iy,pp.imag());
                ay=max(ay,pp.imag());
            }
            res=min(res,max(ax-ix,ay-iy));
        }

        db(res)
    }

    return 0;
}