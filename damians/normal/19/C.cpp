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

#define X 29
#define ull unsigned long long

int tab[100000];
int tlu[100000];
int n;
ull hasze[100003];
ull pX[120003];

inline ull h(int a, int b)//[a..b)
{
    return hasze[a]-pX[b-a]*hasze[b];
}

vi occ[100000];


int main()
{
    pX[0]=1;REP(i,1,110000) pX[i]=X*pX[i-1];
    CZ(n);
    FOR(i,n) CZ(tab[i]);
    FOR(i,n) tlu[i]=tab[i];
    sort(tlu,tlu+n);
    int dl=unique(tlu,tlu+n)-tlu;
    FOR(i,n) tab[i]=lower_bound(tlu,tlu+dl,tab[i])-tlu;
    DBG(vi(tab,tab+n));
    hasze[n]=0;
    REPD(i,n-1,0) hasze[i]=hasze[i+1]*X+tab[i];
    FOR(i,n) occ[tab[i]].pb(i);
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    DBG(h(1,3));
    DBG(h(3,5));
    DBG(occ[3]);
    FOR(i,n)
    {
        FOR(j,occ[i].sz) REP(k,j+1,occ[i].sz-1)
        {
            int z=occ[i][j],x=occ[i][k];
            int ds=x-z;
            if (x+ds<=n && h(x,x+ds)==h(z,z+ds)) {DBG2(j,k);Q.push(mp(ds,z));}
        }
    }
    
    int akt=0;
    while(!Q.empty())
    {
        pii p=Q.top();Q.pop();
        if (p.se>=akt)
        {
            akt=p.se+p.fi;
        }
    }
    printf("%d\n",n-akt);
    REP(j,akt,n-1) printf("%d ",tlu[tab[j]]);
    
    

    return 0;
}