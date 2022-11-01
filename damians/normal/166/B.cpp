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

#define real long long

struct pt
{
    real x;
    real y;
    pt(){x=y=0;}
    pt(real _x,real _y):x(_x),y(_y){}
    bool operator==(pt &a){return (a.x==x && a.y==y);}
    
}; 

typedef vector<pt> polygon;

pt operator+(const pt &a, const pt &b){return pt(a.x+b.x,a.y+b.y);}
pt operator-(const pt &a, const pt &b){return pt(a.x-b.x,a.y-b.y);}
real vec(const pt &a, const pt &b){return a.x*b.y-a.y*b.x;}
real det(const pt &a, const pt &b, const pt &c){return vec(b-a,c-a);}

vector<pt> p;

bool in_convex_pol(pt a)
{

    if (det(p[0],p[1],a)<=0 || det(p[0],p.back(),a)>=0) return 0;
    int lo=1,hi=p.sz-1,mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if (det(p[0],p[mid],a)>=0)
            lo=mid;
        else hi=mid;
    }
    return (det(p[lo],p[lo+1],a)>0);
}



int main()
{
    
    int n;CZ(n);
    FOR(i,n)
    {
        int x,y;CZ2(x,y);
        p.pb(pt(x,y));
    }
    reverse(ALL(p));
    int m;CZ(m);
    bool ok=1;
    FOR(i,m)
    {
        int x,y;CZ2(x,y);
        pt z(x,y);
        if (!in_convex_pol(z)) {ok=0;break;}
    }
    if (!ok) cout<<"NO";
    else cout<<"YES";

    return 0;
}