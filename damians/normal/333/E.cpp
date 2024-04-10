#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define un(v) v.erase(unique(ALL(v)),v.end())
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define real int
//albo int

struct pt
{
    real x;
    real y;
    pt(){x=y=0;}
    pt(real _x,real _y):x(_x),y(_y){}
    bool operator==(pt &a){return (a.x==x && a.y==y);}
    
}; 


typedef vector<pt> polygon;

ostream &operator<<(ostream &s,pt pt1) {return s<<"("<<pt1.x<<","<<pt1.y<<")";}
istream &operator>>(istream &s,pt &pt1){real x,y;s>>x>>y;pt1=pt(x,y);return s;}

bool operator<(pt a,pt b)
{
    if (a.x<b.x) return 1;
    if (a.x>b.x) return 0;
    return a.y<b.y;
}
pt operator+(const pt &a, const pt &b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(const pt &a, const pt &b){return pt(a.x-b.x,a.y-b.y);}
pt operator*(const pt &a, const pt &b){return pt(a.x*b.x-a.y*b.y,b.x*a.y+b.y*a.x);}
pt cnj(pt a){return pt(a.x,-a.y);}
pt operator*(real r,const pt &a){return pt(a.x*r,a.y*r);}
pt operator*(const pt &a,real r){return pt(a.x*r,a.y*r);}
pt operator/(const pt &a,real r){return pt(a.x/r,a.y/r);}
real sqabs(const pt &a){return a.x*a.x+a.y*a.y;}
double abs(const pt &a){return sqrt(a.x*a.x+a.y*a.y);}
double dist(const pt &a,const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
real sqdist(const pt &a,const pt &b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
pt operator/(const pt &a, const pt &b) {return (a*cnj(b))/sqabs(b);}
double arg(const pt &a){return atan2(a.y,a.x);}//z przedzialu [-pi,pi]
bool div(pt a,pt b)//czy a|b w Z[i] a!=0!!
{
    real D=sqabs(a);
    return ((b.x*a.x+a.y*b.y)%D==0 && (a.x*b.y-b.x*a.y)%D==0);
}

real skal(const pt &a, const pt &b){return a.x*b.x+a.y*b.y;}
real vec(const pt &a, const pt &b){return a.x*b.y-a.y*b.x;}
real det(const pt &a, const pt &b, const pt &c){return vec(b-a,c-a);}
double dist(const pt &a, const pt &b, const pt &c)// odleglosc A od prostej BC
{return abs(det(b,c,a))/dist(b,c);}
double dlrzut(const pt &a, const pt &b){return skal(a,b)/abs(b);}//dlugosc (ze znakiem) rzutu A na prosta B
pt rzut(const pt &a, const pt &b, const pt &c)//rzut punktu A na prosta BC
{
    pt d=c-b;
    return b+d*skal(a-b,d)/sqabs(d);
}



bool prawor(pt X,pt Y,pt Z){return det(X,Y,Z)<=0;}

polygon otoczka(vector<pt> ab) 
{
    ab.erase(unique(ALL(ab)),ab.end());
    int l=ab.sz,i,j,k;
    vector<pt> wyn(l+1);
    if (l<3) return ab;
    j=0;
    for(i=0;i<l;i++)
    {
        while (j-2>=0 && prawor(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    k=j;
    for(i=l-2;i>=0;i--)
    {
        while (j-1>=k && prawor(wyn[j-2],wyn[j-1],ab[i])) j--;
        wyn[j++]=ab[i];
    }
    if (wyn[j-1]==wyn[0]) j--;
    //if (j>1 && det(wyn[j-2],wyn[j-1],wyn[0])==0) j--;
    return polygon(wyn.begin(),wyn.begin()+j);
}


int n;
pt p[3033];
int dst[3033][3033];


bool check(int d)
{
    FOR(i,n)
    {
        vector<pt> v;
        FOR(j,n)if(dst[i][j]>=d) v.pb(p[j]);
        v=otoczka(v);
        if (v.sz<2) continue;
        int l=v.sz;
        FOR(i,l)v.pb(v[i]);
        int mx=0;
        int j=0;
        FOR(i,l)
        {
            j=max(j,i);
            while((j+1-i)<l && sqdist(v[i],v[j])<=sqdist(v[i],v[j+1])) j++;
            REMAX(mx,sqdist(v[i],v[j])); 
        }
        if (mx>=d) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)cin>>p[i];
    sort(p,p+n);
    vi v;
    FOR(i,n)FOR(j,n)dst[i][j]=sqdist(p[i],p[j]);
    FOR(i,n)FOR(j,i)v.pb(dst[i][j]);
    sort(ALL(v));un(v);
    int lo=0,hi=v.sz,mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if (check(v[mid])) lo=mid;
        else hi=mid;
    }
    cout<<fixed<<setprecision(10)<<sqrt(v[lo])/2<<"\n";
    
    return 0;
}