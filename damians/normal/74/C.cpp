#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int c[2000004];
int d[2000003];


int n,m;

inline int szuk(int x)
{
    if (c[x]==x) return x;
    int a=szuk(c[x]);
    c[x]=a;
    return a;
}

inline void unia(int x, int y)
{
    DBG2(x,y-m);
    int a=szuk(x),b=szuk(y);
    c[a]=b;
}





int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    if (m<n) swap(m,n);
    FOR(i,2*m+3) c[i]=i;
    d[1]=n;
    int ro=1;
    REP(i,2,m)
    {
        if (d[i-1]==m)
        {
            ro=-1;
        }
        else if (d[i-1]==1) ro=1;
        d[i]=d[i-1]+ro;
        
        DBG(d[i]);
    }
    REP(i,1,m) unia(i,m+d[i]);
    REP(i,1,m) unia(m-i+1,m+m-d[i]+1);
    d[m]=m-n+1;
    REPD(i,m-1,1)
    {
        if (d[i+1]==m)
        {
            ro=-1;
        }
        else if (d[i+1]==1) ro=1;
        d[i]=d[i+1]+ro;
        
        DBG(d[i]);
    }
    REP(i,1,m) unia(i,m+d[i]);
    REP(i,1,m) unia(m-i+1,m+m-d[i]+1);
    int ile=0;
    REP(i,1,2*m) DBG(szuk(i));
    REP(i,1,2*m) if (szuk(i)==i) ile++;
    
    cout<<ile;
    
    

    return 0;
}