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
#define FOREACH(i,t) FORE(i,t)
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
#define wez(x) int x; CZ(x);
#define wez2(x,y) int x,y; CZ2(x,y);
#define wez3(x,y,z) int x,y,z; CZ3(x,y,z);
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
inline void pisz (int x) { printf("%d\n", x); }
#define M 3004
int zaj[M][M];
int gora[M][M];
int prawo[M][M];
pii A[100001],B[100001];
int n;

void wypisz(int ax,int ay,int bx,int by)
{
    vi v;
    FOR(i,n)
    {
        if (ax<=A[i].fi && ay<=A[i].se && B[i].fi<=bx && B[i].se<=by)v.pb(i);
    }
    printf("YES %d\n",v.sz);
    FOR(i,v.sz)printf("%d ",v[i]+1);
}

int sumuj(int ax,int ay,int bx,int by)
{
    return zaj[bx][by]-zaj[ax][by]-zaj[bx][ay]+zaj[ax][ay];
}

vi diag[M+M+M];


int main()
{
    ios_base::sync_with_stdio(0);
    CZ(n);
    FOR(i,M)FOR(j,M)gora[i][j]=j;
    FOR(i,M)FOR(j,M)prawo[i][j]=i;
    FOR(i,n)
    {
        int ax,ay,bx,by;CZ2(ax,ay);CZ2(bx,by);
        A[i]=mp(ax,ay);
        B[i]=mp(bx,by);
        REPD(y,by,ay)
        {
            REMAX(gora[ax][y],by);
            REMAX(gora[bx][y],by);
        }
        REPD(x,bx,ax)
        {
            REMAX(prawo[x][ay],bx);
            REMAX(prawo[x][by],bx);
        }
        diag[M+ax-ay].pb(ax);
        diag[M+bx-by].pb(bx);
        REP(x,ax+1,bx)REP(y,ay+1,by)zaj[x][y]=1;
    }
    //DBG(prawo[2][2]);
    //DBG(prawo[3][2]);
    FOR(x,M)REPD(y,M-2,0) if (gora[x][y]>y) gora[x][y]=gora[x][y+1];
    FOR(y,M)REPD(x,M-2,0) if (prawo[x][y]>x) prawo[x][y]=prawo[x+1][y];
    REP(x,1,M-1)REP(y,1,M-1)zaj[x][y]=zaj[x][y]+zaj[x-1][y]+zaj[x][y-1]-zaj[x-1][y-1];
    FOR(i,3*M)
    {
        vi d=diag[i];
        sort(ALL(d));un(d);
        //if(d.sz){DBG(i-M);DBG(d);}
        FOR(j,d.sz)
        {
            //DBG(j);
            int j1=j+1;
            while(j1<d.sz)
            {
                int ax=d[j],bx=d[j1];
                int ay=-(i-M-ax),by=-(i-M-bx);
                /*DBG(mp(ax,ay));
                DBG(mp(bx,by));
                DBG(prawo[ax][ay]);
                DBG(gora[ax][ay]);*/
                if (prawo[ax][ay]<bx) break;
                if (gora[ax][ay]<by) break;
                if (sumuj(ax,ay,bx,by)!=(bx-ax)*(bx-ax)) break;
                if (prawo[ax][by]>=bx && gora[bx][ay]>=by)
                {
                    wypisz(ax,ay,bx,by);
                    return 0;
                }
                j1++;
            }
        }
        
        
    }
    puts("NO");

    return 0;
}