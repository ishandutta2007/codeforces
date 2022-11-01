#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point
{
    ll x,y;
    point(){x=0;y=0;}
    point(ll a,ll b):x(a),y(b){}
};

struct line
{
    ll a,b,c;
    line(point p,point q)
    {
        a=p.y-q.y;
        b=q.x-p.x;
        c=-a*p.x-b*p.y;
    }
};

bool operator==(const point &a,const point &b){return (a.x==b.x&&a.y==b.y);}
point operator-(const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}
ll cross(point a,point b){return (a.x*b.y-b.x*a.y);}
double dist(point a){return sqrt(a.x*a.x+a.y*a.y);}
double sq(double a){return a*a;}
double dist(point a,array<double,2> b){return sqrt(sq(a.x-b[0])+sq(a.y-b[1]));}
array<double,2> intersect(line one,line two)
{
    double x=-(one.c*two.b-two.c*one.b)/((double)one.a*two.b-two.a*one.b);
    double y=(-one.a*x-one.c)/((double)one.b);
    return {x,y};
}
bool bad(line one,line two)
{
    ll g=gcd(gcd(one.a,one.b),one.c);
    one.a/=g; one.b/=g; one.c/=g;
    g=gcd(gcd(two.a,two.b),two.c);
    two.a/=g; two.b/=g; two.c/=g;
    if(one.a==two.a&&one.b==two.b&&one.c==two.c) return 1;
    one.a*=(-1); one.b*=(-1); one.c*=(-1);
    if(one.a==two.a&&one.b==two.b&&one.c==two.c) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll h;
    cin >> n >> h;
    vector<point> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i].x >> v[i].y;
    point tower(v[n].x,v[n].y+h);
    vector<point> up(n+1);
    up[n]=v[n];
    for(int i=n-1;i>=1;i--)
    {
        up[i]=up[i+1];
        if(cross(v[i]-tower,up[i+1]-tower)>=0) up[i]=v[i];
    }
    double res=0;
    for(int i=1;i<n;i++)
    {
        if(bad(line(v[i],v[i+1]),line(up[i+1],tower))) res+=dist(v[i+1]-v[i]);
        else
        {
            line one(v[i],v[i+1]);
            line two(up[i+1],tower);
            array<double,2> t=intersect(one,two);
            double x=t[0];
            if(x>=v[i+1].x&&cross(v[i+1]-v[i],tower-up[i+1])>0) res+=dist(v[i+1]-v[i]);
            else if(x>=v[i].x&&cross(v[i+1]-v[i],tower-up[i+1])>0) res+=dist(v[i],t);
        }
    }
    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}