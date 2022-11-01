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
#define INF ((1LL<<31)+2)
struct typ
{
    ll v;
    int nr;
    ll masa;
    bool operator<(typ a) const
    {
        if (masa==a.masa)
        {
            if (v==a.v) return nr<a.nr;
            return v>a.v;
        }
        return masa>a.masa;
    }
};
vector<typ> t;//waga,nr,spe
int gosc[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    ll h;
    int k,n;cin>>n>>k>>h;
    t.resize(n);
    FOR(i,n) t[i].nr=i;
    FOR(i,n)
    {
        int a;cin>>a;
        t[i].masa=a;
    }
    FOR(i,n)
    {
        int a;cin>>a;
        t[i].v=a;
    }
    sort(ALL(t));
    long double lo=0.0,hi=INF,mid;
    FOR(dsg,100)
    {
        mid=(hi+lo)/2;
        int akt=k;
        FOR(i,n)
        {
            if (akt*h<=t[i].v*mid)
            {
                gosc[akt]=t[i].nr;
                akt--;
            }
            if (akt==0) break;
        }
        if (akt==0) hi=mid;
        else lo=mid;
    }
    mid=hi;
    int akt=k;
    FOR(i,n) DBG(t[i].nr);
    FOR(i,n)
    {
        if (akt*h<=t[i].v*mid)
        {
            gosc[akt]=t[i].nr;
            akt--;
        }
        if (akt==0) break;
    }
    DBG(hi);
    REP(i,1,k) cout<<gosc[i]+1<<" ";

    return 0;
}