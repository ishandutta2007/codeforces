#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
char mp[1234][1234];
int dis[1234][1234];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int sx,sy,ex,ey;
int n,m,k;
queue<pair<int,int> >Q;
void BFS()
{
	for(int i=0;i<n;i++)
	{
		 for(int j=0;j<m;j++)
		 {
		 	dis[i][j]=0x3f3f3f3f;
		 }
            
	}     
    dis[sx][sy]=0;
    Q.push(make_pair(sx,sy));
    
    while(!Q.empty())
    {
        pair<int,int> tmp= Q.front();
		Q.pop();
        int x=tmp.first;
		int y=tmp.second;
        for(int i=1;i<=k;i++)//right 
        {
            int nx=x+i;
            if(nx>=n||mp[nx][y]=='#') break;
            if(dis[nx][y]>=0x3f3f3f3f)
            {
                dis[nx][y]=dis[x][y]+1;
                if(nx==ex&&y==ey) return;
                Q.push(make_pair(nx,y));
            }
        }
        for(int i=1;i<=k;i++)//left
        {
            int nx=x-i;
            if(nx<0||mp[nx][y]=='#') break;
            if(dis[nx][y]>=0x3f3f3f3f)
            {
                dis[nx][y]=dis[x][y]+1;
                if(nx==ex&&y==ey) return;
                Q.push(make_pair(nx,y));
            }
        }
        for(int i=1;i<=k;i++)//down
        {
            int ny=y+i;
            if(ny>=m||mp[x][ny]=='#') break;
            if(dis[x][ny]>=0x3f3f3f3f)
            {
                dis[x][ny]=dis[x][y]+1;
                if(x==ex&&ny==ey) return;
                Q.push(make_pair(x,ny));
            }
        }
        for(int i=1;i<=k;i++)//up
        {
            int ny=y-i;
            if(ny<0||mp[x][ny]=='#') break;
            if(dis[x][ny]>=0x3f3f3f3f)
            {
                dis[x][ny]=dis[x][y]+1;
                if(x==ex&&ny==ey) return;
                Q.push(make_pair(x,ny));
            }
        }
    }
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
	}
	sx=read(),sy=read(),ex=read(),ey=read();
	sx--,sy--,ex--,ey--;
	BFS();
	if(dis[ex][ey]>=0x3f3f3f3f) cout<<"-1"<<endl;
	else cout<<dis[ex][ey]<<endl; 
	return 0;
}