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

char s[1<<20];
int dp[50002][102];
int ne[222][50002];

char pa[1111];

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%s",s);
    int n=strlen(s);
    FOR(i,n+1)dp[i][0]=i-1;
    FOR(i,n+1)dp[i][1]=i;
    FOR(c,222)
    {
        int w=n;
        ne[c][n]=n;
        REPD(i,n-1,0)
        {
            if (s[i]==c) w=i;
            ne[c][i]=w;
        }
    }
    int mx=1;
    REP(d,2,100)
    {
        dp[n][d]=n;
        REPD(i,n-1,0)
        {
            dp[i][d]=dp[i+1][d];
            if (dp[i+1][d-2]<n) REMIN(dp[i][d],ne[s[i]][dp[i+1][d-2]+1]);
        }
        if (dp[0][d]<n) mx=d;
    }
    //DBG(mx);
    int d=mx;
    int x=0;
    int cnt=0;
    while(d>0)
    {

        while(dp[x][d]==dp[x+1][d]) x++;

        pa[cnt]=pa[mx-cnt-1]=s[x];
        x++;
        cnt++;
        d-=2;
    }
    pa[mx]=0;
    printf("%s\n",pa);
    

    return 0;
}