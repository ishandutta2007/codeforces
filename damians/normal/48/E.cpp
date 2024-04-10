#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
int h,t,R,n,m;
int tail[304][2],head[304][2];
int g[501][501];
int bu[501][501];
int petla;
map<pair<int,int>, int> ind;
vector<pair<int,int> > top;
int dp[1000005];

void DFS(int a,int b)
{
    if (g[a][b] && !bu[a][b]) {petla=1;return;}
    if (g[a][b]) return;
    g[a][b]=1;
    int x,y;
    REP(i,1,min(a,n))
        {
            x=a-i;
            y=b;
            x+=head[i][0];
            y+=head[i][1];
            if (x+y>R) continue;
            else
            {
                DFS(x,y);
            }
        }
        REP(i,1,min(b,m))
        {
            x=a;
            y=b-i;
            x+=tail[i][0];
            y+=tail[i][1];
            if (x+y>R) continue;
            else
            {
                DFS(x,y);
            }
        }
    bu[a][b]=1;
    top.pb(mp(a,b));
    ind[mp(a,b)]=top.sz()-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(i,300) FOR(j,2) {tail[i][j]=head[i][j]=0;}
    FOR(i,300) FOR(j,300) g[i][j]=-1;
    cin>>h>>t>>R;
    cin>>n;
    FOR(i,n) cin>>head[i+1][0]>>head[i+1][1];
    cin>>m;
    FOR(i,m) cin>>tail[i+1][0]>>tail[i+1][1];
    g[h][t]=0;
    queue<pair<int,int> > Q;
    Q.push(mp(h,t));
   petla=0;
    int mx=0;
    pair<int,int> u;
    int x,y;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        //DBG(u.fi);
        //DBG(u.se);
        //cout<<endl;
        mx=max(mx,g[u.fi][u.se]);
        if (u.fi==0 && u.se==0)
        {
            cout<<"Ivan"<<endl;
            cout<<g[u.fi][u.se]<<endl;
            return 0;
        }
        REP(i,1,min(u.fi,n))
        {
            x=u.fi-i;
            y=u.se;
            x+=head[i][0];
            y+=head[i][1];
            if (x+y>R) continue;
            if (g[x][y]!=-1) petla=1;
            else
            {
                g[x][y]=g[u.fi][u.se]+1;
                Q.push(mp(x,y));
            }
        }
        REP(i,1,min(u.se,m))
        {
            x=u.fi;
            y=u.se-i;
            x+=tail[i][0];
            y+=tail[i][1];
            if (x+y>R) continue;
            if (g[x][y]!=-1) petla=1;
            else
            {
                g[x][y]=g[u.fi][u.se]+1;
                Q.push(mp(x,y));
            }
        }
    }
    FOR(i,300) FOR(j,300) g[i][j]=0;
    FOR(i,300) FOR(j,300) bu[i][j]=0;
    petla=0;
    mx=0;
    int roz;
    DFS(h,t);
    if (petla)
        cout<<"Draw"<<endl;
    else
    {
        int a,b;
        reverse(ALL(top));
        roz=top.sz()-1;
        FOR(i,top.sz()) dp[i]=0;
        FOR(j,top.sz())
        {
            mx=max(dp[j],mx);
            a=top[j].fi;
            b=top[j].se;
            REP(i,1,min(a,n))
            {
                x=a-i;
                y=b;
                x+=head[i][0];
                y+=head[i][1];
                if (x+y>R) continue;
                else
                {
                    dp[roz-ind[mp(x,y)]]=max(dp[j]+1,dp[roz-ind[mp(x,y)]]);
                    
                }
            }
            REP(i,1,min(b,m))
            {
                x=a;
                y=b-i;
                x+=tail[i][0];
                y+=tail[i][1];
                if (x+y>R) continue;
                else
                {
                    dp[roz-ind[mp(x,y)]]=max(dp[j]+1,dp[roz-ind[mp(x,y)]]);
                }
            }
        }
        cout<<"Zmey"<<endl;
        cout<<mx+1<<endl;
    }
    
    return 0;
}