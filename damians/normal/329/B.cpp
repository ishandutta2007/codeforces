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

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
#define INF (1<<23)
int d[1<<10][1<<10];

char s[1<<10][1<<10];

int main()
{
    ios_base::sync_with_stdio(0);
    int r,c;CZ2(r,c);
    FOR(i,r) scanf("%s",s[i+1]+1);
    REP(i,1,r)REP(j,1,c) d[i][j]=INF;
    queue<pii> q;
    REP(i,1,r)REP(j,1,c)
    {
        if (s[i][j]=='E')
        {
            q.push(mp(i,j));
            d[i][j]=0;
        }
    }
    while(q.sz)
    {
        pii p=q.front();q.pop();
        int x=p.fi,y=p.se;
        FOR(k,4)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if ((isdigit(s[xx][yy]) || s[xx][yy]=='S') && d[xx][yy]==INF)
            {
                d[xx][yy]=d[x][y]+1;
                q.push(mp(xx,yy));
            }
        }
    }
    int wyn=0;
    int odl=0;
    REP(i,1,r)REP(j,1,c)if (s[i][j]=='S')odl=d[i][j];
    REP(i,1,r)REP(j,1,c)if (isdigit(s[i][j]) && d[i][j]<=odl) wyn+=(s[i][j]-'0');
    cout<<wyn;
    return 0;
}