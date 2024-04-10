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

vi kol;
int n,m;
int wyn[1000003];


bool dod(int nr,int c)
{
    if (nr==n)
    {
        if (wyn[1]!=c && wyn[n-1]!=c)
        {
            wyn[0]=wyn[n]=c;
            return 1;
        }
        return 0;
    }
    if (wyn[nr-1]!=c && wyn[nr+1]!=c) 
    {
        wyn[nr]=c;
        return 1;
    }
    return 0;
    
}

pii tab[50];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    FOR(i,m) 
    {
        int a;
        cin>>a;
        tab[i]=mp(a,i+1);
    }
    sort(tab,tab+m);
    reverse(tab,tab+m);
    REP(i,1,n)
    {
        if (i%2) kol.pb(i);
    }
    REP(i,1,n)
    {
        if (!(i%2)) kol.pb(i);
    }
    FOR(i,n+2) wyn[i]=-1;
    int z=0;
    FOR(i,m)
    {
        if (z==n) break;
        FOR(j,tab[i].fi)
        {
            if (z==n) break;
            if (dod(kol[z],tab[i].se))
            {
                z++;
            }
            else break;
        }
    }
    if (z==n)
    {
        FOR(i,n) cout<<wyn[i+1]<<" ";
    }
    else cout<<-1;
    
    

    return 0;
}