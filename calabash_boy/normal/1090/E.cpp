/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 18:37:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,nx,ny,dx,dy,cnt;
int d[100][100];
bool board[100],certain[100];
vector<int> G[MAXN];
vector<P> path;
int find_id(int x,int y)
{
    return (x-1)*8+y;
}
void add_edge(int x,int y,int xx,int yy)
{
    if(xx<1||xx>8||yy<1||yy>8) return;
    int id1=find_id(x,y),id2=find_id(xx,yy);
    G[id1].push_back(id2);G[id2].push_back(id1);
    d[id1][id2]=d[id2][id1]=1;
}
void check(int x,int y)
{
    int id=find_id(x,y); d[id][id]=0;
    add_edge(x,y,x-1,y-2);add_edge(x,y,x-1,y+2);
    add_edge(x,y,x+1,y-2);add_edge(x,y,x+1,y+2);
    add_edge(x,y,x-2,y-1);add_edge(x,y,x-2,y+1);
    add_edge(x,y,x+2,y-1);add_edge(x,y,x+2,y+1);
}
void floyd_warshall()
{
    for(int k=1;k<=64;k++)
        for(int i=1;i<=64;i++)
          for(int j=1;j<=64;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
void output(P p)
{
    int x=p.F%8,y=(p.F-1)/8;if(x==0) x+=8;
    printf("%c%d-",x+'a'-1,y+1);
    x=p.S%8,y=(p.S-1)/8;if(x==0) x+=8;
    printf("%c%d\n",x+'a'-1,y+1);
}
void findrook()
{
    while(nx<=8&&!board[find_id(nx,ny)])
    {
        ny++;if(ny>8) {ny-=8; nx++;}
    }
}
void findpath(int src,int dest)
{
    assert(board[src]);
    if(d[src][dest]==0) return;
    for(auto to:G[src])
    {
        if(d[to][dest]<d[src][dest])
        {
            if(board[to]) {findpath(to,dest); path.push_back(P(src,to)); board[src]=false; board[to]=true; return;}
            path.push_back(P(src,to)); board[src]=false; board[to]=true;
            findpath(to,dest); return;
        }
    }
}
void solve()
{
    while(nx<=8)
    {
        dy++;if(dy>8) {dy-=8; dx++;}
        //printf("%d %d\n",dx,dy);
        nx=dx;ny=dy;findrook();
        if(nx>8) return;
        findpath(find_id(nx,ny),find_id(dx,dy));certain[find_id(dx,dy)]=true;
    }
}
string str;
int main()
{
    scanf("%d",&n);memset(board,false,sizeof(board));memset(certain,false,sizeof(certain));
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int x=(str[1]-'0'-1)*8+(str[0]-'a'+1);
        board[x]=true;
    }
    for(int i=0;i<=70;i++)
        for(int j=0;j<=70;j++)  
            d[i][j]=INF;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            check(i,j);
    floyd_warshall();
    nx=1,ny=0;dx=1,dy=0;
    solve();printf("%d\n",(int)path.size());
    assert(path.size()<1500);
    for(int i=0;i<(int)path.size();i++) output(path[i]);
    return 0;
}