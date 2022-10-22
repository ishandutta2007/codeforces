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

typedef complex<ll> point;
typedef vector<point> polygon;

const double eps = 1e-11;

ll cross(point a, point b) { return imag(conj(a) * b); }

int quad(point x)
{
    if(x.imag()>=0 && x.real()>0) return 0;
    if(x.imag()>0 && x.real()<=0) return 1;
    if(x.imag()<=0 && x.real()<0) return 2;
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.precision(30);
    cout<<fixed;

    int n;
    cin >> n;
    polygon p;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin >> x >> y;
        p.push_back(point(x,y));
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
//        db("")
//        db(i)
        vector<point> angs;
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            point v=p[j]-p[i];
            angs.push_back(v);
        }

        sort(all(angs),[&](point &a,point &b){
            if(quad(a)!=quad(b)) return quad(a)<quad(b);
            return cross(a,b)>0;
        });

//        for(auto y : angs)
//            cout << y.real() << ' ' << y.imag() << '\n';

        for(int j=0;j<n-1;j++)
            angs.push_back(angs[j]);

        int act=0,pos=1;
        while(cross(angs[0],angs[pos])>0)
            pos++;
        int r=pos;
        for(int l=1;l<pos;l++)
        {
            while(cross(angs[l],angs[r])>0)
                r++;
            act+=(r-pos);
        }
        res+=act;
//        cout << 0 << ' ' << pos << ' ' << act << '\n';
        for(int j=1;j<n-1;j++)
        {
            int pa=pos;
            if(j==pos)
                pos++;
            while(cross(angs[j],angs[pos])>0)
                pos++;
            int dif=pos-pa;
            int p1=pa-j;
            int p2=n-1-p1-dif;
            act+=(dif*(p2-p1));
//            cout << j << ' ' << pos << ' ' << act << '\n';
            res+=act;
        }
//        db("")
    }
    db((res*(n-4))/6)

    return 0;
}
/**
5
-1 0
1 0
-10 -1
10 -1
0 3

5
0 0
1000000000 0
999999999 1
999999999 -1
-1000000000 1

8
0 1
1 2
2 2
1 3
0 -1
-1 -2
-2 -2
-1 -3

4
-1 0
1 0
0 3
0 2

10
588634631 265299215 -257682751 342279997 527377039 82412729 145077145 702473706 276067232 912883502 822614418 -514698233 280281434 -41461635 65985059 -827653144 188538640 592896147 -857422304 -529223472
**/