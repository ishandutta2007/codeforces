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

#define M (1<<19)

int n,m;
double d[2*M];

int A,B;
double X;

void mn(int l,int r,int nr)
{
    if (A<=l && r<=B)
    {
        d[nr]*=X;
        return;
    }
    if (l>B || r<A) return;
    mn(l,(l+r)/2,nr*2);
    mn((l+r)/2+1,r,nr*2+1);
}

void mnoz(int a,int b,double x)
{
    A=a;
    B=b;
    X=x;
    mn(0,M-1,1);
}

double query(int nr)
{
    nr+=M;
    double wyn=1.0;
    while(nr) {wyn*=d[nr];nr/=2;}
    return wyn;
}

vi v;

int get(int x)
{
    return lower_bound(ALL(v),x)-v.begin();
}

int a[111111],h[111111],l[111111],r[111111];
int b[11111],z[11111];

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,2*M) d[i]=1.0;
    cin>>n>>m;
    FOR(i,n)
    {
        cin>>a[i]>>h[i]>>l[i]>>r[i];
        v.pb(a[i]);
        v.pb(a[i]-h[i]);
        v.pb(a[i]+h[i]);
    }
    FOR(i,m)
    {
        cin>>b[i]>>z[i];
        v.pb(b[i]);
    }
    sort(ALL(v));
    un(v);
    //DBG(v);
    FOR(i,n)
    {
        double lp=l[i]*0.01;
        double rp=r[i]*0.01;
        int a1,a2;
        a1=get(a[i]-h[i]);
        a2=get(a[i]); 
        //DBG(mp(a1,a2-1));
        mnoz(a1,a2-1,1.0-lp);
        a1=get(a[i]+h[i]);
        mnoz(a2+1,a1,1.0-rp);
        //DBG(mp(a2+1,a1));
    }
    double wyn=0.0;
    FOR(i,m)
    {
        wyn+=z[i]*query(get(b[i]));
    }
    cout<<setprecision(9)<<fixed<<wyn;
    

    return 0;
}