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


int x[111111];
int n,a,b;

bool check(vi wyn)
{
    set<int> A,B;
    FOR(i,n)if(wyn[i]==0)A.insert(x[i]);else B.insert(x[i]);
    FORE(it,A)if (!IN(a-*it,A)) return 0;
    FORE(it,B)if (!IN(b-*it,B)) return 0;
    return 1;
}
map<int,int> nr;

int getuj(int x)
{
    if (!IN(x,nr)) return -1;
    return nr[x];
}

int h[111111];

bool probaA(int p)
{
    vi v;
    v.pb(p);
    set<int> d;
    d.insert(p);
    while(v.sz)
    {
        p=v.back();v.pop_back();
        int w=x[p];
        if (getuj(a-w)==-1) return 0;
        if (!IN(getuj(a-w),d))
        {
            d.insert(getuj(a-w));
            v.pb(getuj(a-w));
        }
        if (getuj(b-w)==-1) continue;
        if (!IN(getuj(b-w),d))
        {
            d.insert(getuj(b-w));
            v.pb(getuj(b-w));
        }
    }
    FORE(it,d)h[*it]=0;
    return 1;
}

bool probaB(int p)
{
    vi v;
    v.pb(p);
    set<int> d;
    d.insert(p);
    while(v.sz)
    {
        p=v.back();v.pop_back();
        int w=x[p];
        if (getuj(b-w)==-1) return 0;
        if (!IN(getuj(b-w),d))
        {
            d.insert(getuj(b-w));
            v.pb(getuj(b-w));
        }
        if (getuj(a-w)==-1) continue;
        if (!IN(getuj(a-w),d))
        {
            d.insert(getuj(a-w));
            v.pb(getuj(a-w));
        }
    }
    FORE(it,d)h[*it]=1;
    return 1;
}

void go()
{
    FOR(i,n)h[i]=-1;
    FOR(i,n)
    {
        if (h[i]==-1)
        {
            if (probaA(i))continue;
            if (probaB(i))continue;
            DBG(i);
            puts("NO");
            return;
        }
    }
    puts("YES");
    FOR(i,n)printf("%d ",h[i]);
}

int main()
{
    CZ3(n,a,b);
    FOR(i,n)CZ(x[i]);
    FOR(i,n)nr[x[i]]=i;
    /*if (a==b)
    {
        vi v(n,0);
        if (check(v))
        {
            puts("YES");
            FOR(i,n) printf("%d ",v[i]);
        }
        else puts("NO");
        return 0;
    }*/
    go();

    return 0;
}