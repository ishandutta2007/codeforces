#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
}p[1000];
int maze[1000][1000];
int curx,cury;
int cntx[1000],cnty[1000];
bool move(int dx,int dy)
{
    curx+=dx,cury+=dy;
    if(maze[curx][cury])
    {
        if(dx) curx-=dx;
        else cury-=dy;
    }
    cout<<curx<<" "<<cury<<endl;
    int k=0,nx=0,ny=0;
    cin>>k>>nx>>ny;
    if(k+nx+ny==-3||k+nx+ny==0) return 0;
    maze[p[k].x][p[k].y]=0;
    cntx[p[k].x]--;cnty[p[k].y]--;
    cntx[nx]++,cnty[ny]++;
    maze[nx][ny]=1;
    p[k].x=nx;p[k].y=ny;
    return 1;
}
int calc()
{
    int d[5]={0};
    for(int i=1;i<=666;i++)
    {
        if(p[i].x<500&&p[i].y<500) d[1]++,d[2]++,d[3]++;
        else if(p[i].y<500) d[2]++,d[3]++,d[4]++;
        else if(p[i].y>500&&p[i].x>500) d[1]++,d[4]++,d[3]++;
        else d[1]++,d[2]++,d[4]++; 
    }
    int tar=0;
    for(int i=1;i<=4;i++)
        tar=max(tar,d[i]);
    for(int i=1;i<=4;i++)
        if(tar==d[i]) return i;
}
void solve()
{
    while(curx<500) move(1,0);
    while(curx>500) move(-1,0);
    while(cury<500) move(0,1);
    while(cury>500) move(0,-1);
    int direct=calc();
    if(direct==1) while(move(-1,1));
    else if(direct==2) while(move(-1,-1));
    else if(direct==3) while(move(1,-1));
    else while(move(1,1));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cntx,0,sizeof(cntx));
    memset(cnty,0,sizeof(cnty));
    cin>>curx>>cury;
    for(int i=1;i<=666;i++)
    {
        cin>>p[i].x>>p[i].y;
        maze[p[i].x][p[i].y]=1;
        cntx[p[i].x]++;
        cnty[p[i].y]++;
    }
    solve();

}