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
#define MAX(a,b,c) max(a,max(b,c))
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int n,m,c;
int x[1000000];
int a[1000000],b[1000000];
double p[1000000];
double s[1000000];

struct node
{
    double ml,mr,mx,sm;
    node(double _ml,double _mr, double _mx,double _sm):ml(_ml),mr(_mr),mx(_mx),sm(_sm){}
    node(){}//:ml(0),mr(0),mx(0),sm(0){}
};
inline node operator+(const node &a,const node &b)
{
    node wyn;
    wyn.sm=a.sm+b.sm;
    wyn.ml=max(a.ml,a.sm+max(0.00,b.ml));
    wyn.mr=max(b.mr,b.sm+max(0.0,a.mr));
    wyn.mx=MAX(a.mr+b.ml,a.mx,b.mx);
    return wyn;
}
#define M (1<<19)
#define INF 1020000000

node d[2*M];
int A,B;

void zmien(int a,double val)
{
    d[a+M]=node(val,val,val,val);
    int nr=(a+M)/2;
    while(nr)
    {
        d[nr]=d[nr*2]+d[nr*2+1];
        nr/=2;
    }
}

node szuk(int l,int p, int nr)
{
    if (A<=l && p<=B) return d[nr];
    if (B<=(l+p)/2) return szuk(l,(l+p)/2,nr*2);
    if (A>(l+p)/2) return szuk((l+p)/2+1,p,nr*2+1);
    return szuk(l,(l+p)/2,nr*2)+szuk((l+p)/2+1,p,nr*2+1);
}


double go(int _a,int _b)
{
    A=_a;
    B=_b;
    return szuk(0,M-1,1).mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>c;
    FOR(i,n) cin>>x[i];
    FOR(i,n-1) cin>>p[i];
    FOR(i,n) p[i]/=100;
    FOR(i,m) cin>>a[i]>>b[i];
    s[0]=0;
    d[0+M]=node(0,0,0,0);
    FOR(i,n-1)
    {
        s[i+1]=-c*p[i]+(x[i+1]-x[i])*.5;
        d[(i+1)+M]=node(s[i+1],s[i+1],s[i+1],s[i+1]);
    }
    REPD(i,M-1,1) d[i]=d[i*2]+d[i*2+1];
    FOR(i,n) DBG(s[i]);
    double best=0;
    FOR(i,m)
    {
        int A=a[i],B=b[i];
        B--;
        double bb=max(0.0,go(A,B));
        DBG(mp(A,B));
        DBG(bb);
        best+=bb;
    }
    cout<<setprecision(9)<<fixed<<best<<"\n";
    

    return 0;
}