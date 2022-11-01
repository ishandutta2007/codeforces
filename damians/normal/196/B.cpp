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

#define NIC (1<<30)

char s[2001][2001];
int odwx[1502][1502];
int odwy[1502][1502];

bool suc;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;

void dfs(int a,int b,int nrx,int nry)
{
    if (suc) return;
    if (odwx[a][b]!=NIC)
    {
        if (mp(odwx[a][b],odwy[a][b])!=mp(nrx,nry))
        {
            suc=1;
            return;
        }
        return;
    }
    odwx[a][b]=nrx;
    odwy[a][b]=nry;
    FOR(k,4)
    {
        int mx=nrx;
        int my=nry;
        int a1=(a+dx[k]);
        int b1=(b+dy[k]);
        if (a1<0) mx--;
        if (b1<0) my--;
        if (a1>=n) mx++;
        if (b1>=m) my++;
        a1+=n;
        b1+=m;
        while(a1>=n) a1-=n;
        while(b1>=m) b1-=m;
        
        if (s[a1][b1]!='#')
        {
            dfs(a1,b1,mx,my);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    CZ2(n,m);
    FOR(i,n) scanf("%s",s[i]);
    int a,b;
    FOR(i,n) FOR(j,m)
    {
        if (s[i][j]=='S')
        {
            a=i;
            b=j;
            s[i][j]='.';
        }
    }
    suc=0;
    FOR(i,n) FOR(j,m) odwx[i][j]=NIC;
    dfs(a,b,0,0);
    if (suc) puts("Yes");
    else puts("No");
    

    return 0;
}