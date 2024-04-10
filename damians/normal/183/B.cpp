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

int best[1000002];
polygon p;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    p.resize(m);
    REP(i,1,n) best[i]=1;
    FOR(i,m)
    {
        cin>>p[i];
    }
    FOR(i,m) FOR(j,m)
    {
        int A=0;
        if (p[i].y<p[j].y)
        {
            if (p[i].x==p[j].x)
            {
                A=p[i].x;
            }
            else
            {
                ll a=p[j].x-p[i].x;
                ll b=p[j].y-p[i].y;
                if (a*(p[i].y)%b) continue;
                ll a0=p[i].x-a*(p[i].y)/b;
                if (a0<1 || a0>n) continue;
                A=a0;
            }
if (A<1 || A>n) continue;
            int ile=0;
            FOR(k,m)
            {
                if (det(p[i],p[j],p[k])==0)
                {
                    ile++;
                }
            }
            REMAX(best[A],ile);
        }
    }
    ll sum=0;
    REP(i,1,n) DBG(best[i]);
    REP(i,1,n) sum+=best[i];
    cout<<sum;
    return 0;
}