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

string s[2];
int czas[1000002][2];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;cin>>n>>k;
    cin>>s[0]>>s[1];
    queue<pii> Q;
    FOR(i,n+1) FOR(j,2) czas[i][j]=-1;
    czas[0][0]=0;
    Q.push(mp(0,0));
    DBG(k);
    while(Q.sz)
    {
        pii u=Q.front();Q.pop();
        if (czas[u.fi][u.se]>u.fi) continue;
        if (u.fi+k>=n)
        {
            puts("YES");
            return 0;
        }
        DBG(u);
        int x=u.fi;
        int y=u.se;
        int c=czas[x][y];
        if (s[y][x+1]=='-' && czas[x+1][y]==-1)
        {
            czas[x+1][y]=c+1;
            Q.push(mp(x+1,y));
        }
        DBG("OK");
        if (x && s[y][x-1]=='-' && czas[x-1][y]==-1)
        {
            czas[x-1][y]=c+1;
            Q.push(mp(x-1,y));
        }
        DBG("OK");
        if (s[1-y][x+k]=='-' && czas[x+k][1-y]==-1)
        {
            czas[x+k][1-y]=c+1;
            Q.push(mp(x+k,1-y));
        }
        DBG("OK");
    }
    puts("NO");
    

    return 0;
}