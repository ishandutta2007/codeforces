#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double eps=1e-9;

struct pt
{
    double x=0,y=0;
    friend pt mid(pt a,pt b){return pt{(a.x+b.x)/2,(a.y+b.y)/2};}
};

struct poly
{
    double a=0,b=0,c=0;
    friend poly operator+(const poly &a,const poly &b){return poly{a.a+b.a,a.b+b.b,a.c+b.c};}
    friend poly operator-(const poly &a,const poly &b){return poly{a.a-b.a,a.b-b.b,a.c-b.c};}
    double eval(double x){return (a*x*x+b*x+c);}
};

struct sweeper
{
    poly p={0,0,0};
    vector<pair<double,poly>> e;
    int idx=0;
    int sz=0;
    void add(pt a,pt b,double d)
    {
        double h=b.y-a.y;
        double l=abs(a.x-b.x);
        double x0=min(a.x,b.x);
        double x1=max(a.x,b.x);
        if(l>eps)
        {
            poly one={d*h/(2*l),-d*2*x0*h/(2*l),d*x0*x0*h/(2*l)};
            e.push_back({x0,one});
            poly two={0,d*h,d*(h*l/2-x1*h)};
            e.push_back({x1,two-one});
        }
        else e.push_back({x1,poly{0,d*h,-d*x1*h}});
    }
    void ini()
    {
        ranges::sort(e,[&](const pair<double,poly> &a,const pair<double,poly> &b){return (a.first<b.first);});
        sz=e.size();
    }
    double mv(double x)
    {
        while(idx<sz&&e[idx].first<=x+eps)
        {
            p=p+e[idx].second;
            idx++;
        }
        return p.eval(x);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<array<ll,2>> v(n);
    const ll inf=(1<<30);
    array<ll,2> mn={inf,-1};
    array<ll,2> mx={-inf,-1};
    vector<ll> ys;
    for(int i=0;auto &[x,y]:v)
    {
        cin >> x >> y;
        mn=min(mn,{y,i});
        mx=max(mx,{y,i});
        ys.push_back(y);
        i++;
    }
    ranges::sort(ys);
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    auto gen=[&](int l,int r)->vector<pt>
    {
        vector<array<ll,2>> p;
        for(int i=l;i!=r;i=(i+1)%n) p.push_back(v[i]);
        p.push_back(v[r]);
        ranges::sort(p,[&](const array<ll,2> &a,const array<ll,2> &b){return (a[1]<b[1]);});
        int m=p.size();
        vector<pt> t;
        int a=0;
        for(int y:ys)
        {
            while(a<m&&p[a][1]<=y) a++;
            if(p[a-1][1]==y) t.push_back(pt{double(p[a-1][0]),double(p[a-1][1])});
            else
            {
                auto [x1,y1]=p[a-1];
                auto [x2,y2]=p[a];
                double x=(x1+(x2-x1)*(y-y1)/double(y2-y1));
                t.push_back(pt{x,double(y)});
            }
        }
        return t;
    };
    vector<pt> l=gen(mn[1],mx[1]);
    vector<pt> r=gen(mx[1],mn[1]);
    if(l[1].x>r[1].x) swap(l,r);
    int m=l.size();
    sweeper one,two;
    double area=0;
    for(int i=0;i+1<m;i++)
    {
        pt a=l[i];
        pt b=r[i];
        pt c=r[i+1];
        pt d=l[i+1];
        pt e=mid(a,b);
        pt f=mid(c,d);
        one.add(a,d,1);
        one.add(e,f,-1);
        two.add(e,f,1);
        two.add(b,c,-1);
        area+=((b.x-a.x+c.x-d.x)/2*(d.y-a.y));
    }
    one.ini();
    two.ini();
    vector<array<int,2>> queries(q);
    for(int i=0;auto &[x,id]:queries)
    {
        cin >> x;
        id=(i++);
    }
    ranges::sort(queries);
    vector<double> res(q,0);
    for(auto [x,id]:queries) res[id]=area-one.mv(x)+two.mv(x);
    for(int i=0;i<q;i++) cout << fixed << setprecision(10) << res[i] << "\n";
    return 0;
}