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
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG1
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


#define real long long
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

bool operator<(const pt &a, const pt &b)
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

real skal(const pt &a, const pt &b){return a.x*b.x+a.y*b.y;}
real vec(const pt &a, const pt &b){return a.x*b.y-a.y*b.x;}
real det(const pt &a, const pt &b, const pt &c){return vec(b-a,c-a);}



bool prawor(pt X,pt Y,pt Z){return det(X,Y,Z)<=0;}

polygon otoczka(vector<pt> ab) 
{
    sort(ab.begin(),ab.end());
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

vector<string> v;



bool jest(string s,char c)
{
    FOR(i,s.sz) if (s[i]==c) return 1;
    return 0;
}

ll d(pt a,pt b)
{
    return max(abs(a.x-b.x),abs(a.y-b.y));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n)
    {
        string s;cin>>s;
        v.pb(s);
    }
    int m1=0,m2=0,n1=0,n2=0;
    polygon p;
    p.pb(pt(0,0));
    //"UL", "UR", "DL", "DR" or "ULDR"
    FOR(i,n)
    {
        if (v[i]=="UL")
        {
            polygon p2;
            FOR(i,p.sz) p2.pb(pt(p[i].x-1,p[i].y));
            FOR(i,p.sz) p2.pb(pt(p[i].x,p[i].y+1));
            p=otoczka(p2);
        }
        if (v[i]=="UR")
        {
            polygon p2;
            FOR(i,p.sz) p2.pb(pt(p[i].x+1,p[i].y));
            FOR(i,p.sz) p2.pb(pt(p[i].x,p[i].y+1));
            p=otoczka(p2);
        }
        if (v[i]=="DL")
        {
            polygon p2;
            FOR(i,p.sz) p2.pb(pt(p[i].x-1,p[i].y));
            FOR(i,p.sz) p2.pb(pt(p[i].x,p[i].y-1));
            p=otoczka(p2);
        }
        if (v[i]=="DR")
        {
            polygon p2;
            FOR(i,p.sz) p2.pb(pt(p[i].x+1,p[i].y));
            FOR(i,p.sz) p2.pb(pt(p[i].x,p[i].y-1));
            p=otoczka(p2);
        }
        if (v[i]=="ULDR")
        {
            polygon p2;
            FOR(i,p.sz) p2.pb(pt(p[i].x-1,p[i].y));
            FOR(i,p.sz) p2.pb(pt(p[i].x,p[i].y+1));
            FOR(i,p.sz) p2.pb(pt(p[i].x+1,p[i].y));
            FOR(i,p.sz) p2.pb(pt(p[i].x,p[i].y-1));
            p=otoczka(p2);
        }
    }
    DBG(p);
    ll w1,w2;
    if (p.sz==2)
    {
        w1=d(p[0],p[1])+1;
        w2=1;
    }
    else
    {
        w1=d(p[0],p[1])+1;
        w2=d(p[1],p[2])+1;
    }
    cout<<w1*w2;
    

    return 0;
}