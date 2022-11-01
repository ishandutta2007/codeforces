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

struct quad
{
    int a,b,c,d;
    quad(int _a,int _b,int _c,int _d)
    {
        a=_a;
        b=_b;
        c=_c;
        d=_d;
    }
    bool operator<(const quad& Q) const
    {
        return mp(mp(a,b),mp(c,d))<mp(mp(Q.a,Q.b),mp(Q.c,Q.d));
    }
};

map<quad,int> mem[16];

int dl(int a,int b,int c,int d,int k)
{
    if (b<a || d<c) return 0;
    if (k==1) return 1;
    if (k<=15 && IN(quad(a,b,c,d),mem[k])) return mem[k][quad(a,b,c,d)];
    int pol=(1<<(k-1))-1;
    if (a<=c && d<=b) return d-c+1;
    if (c<=a && b<=d) return b-a+1;
    ll w1,w2;
    w1=max(a,c);
    w2=min(b,d);
    int len=0;
    if (w1<=w2) len=w2-w1+1;
    if (b<=pol && d<=pol) REMAX(len,dl(a,b,c,d,k-1));
    else if (a>pol+1 && c>pol+1) REMAX(len,dl(a-pol-1,b-pol-1,c-pol-1,d-pol-1,k-1));
    else
    {
        REMAX(len,dl(a,min(b,pol),c,min(d,pol),k-1));
        REMAX(len,dl(a,min(b,pol),max(pol+2,c)-pol-1,d-pol-1,k-1));
        REMAX(len,dl(max(pol+2,a)-pol-1,b-pol-1,max(pol+2,c)-pol-1,d-pol-1,k-1));
        REMAX(len,dl(c,min(d,pol),max(pol+2,a)-pol-1,b-pol-1,k-1));
    }
    if (k<=15) mem[k][quad(a,b,c,d)]=len;
    return len;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll a,b,c,d;cin>>a>>b>>c>>d;
    cout<<dl(a,b,c,d,30);

    return 0;
}