#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=25,L=(1<<22)-1;
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int n,m,vn,bn,ans;
char s[maxn][maxn];
int val[9],vx[9],vy[9],bx[9],by[9],sx,sy;
int f[maxn][maxn][1<<8][1<<8];

struct state
{
    int x,y,vs,bs;
    state(){}
    state(int x_,int y_,int vs_,int bs_)
    {x=x_;y=y_;vs=vs_;bs=bs_;}
}q[L+1];
int qh,qt;

void init()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]>='0'&&s[i][j]<='9')
            {
                vn=max(vn,s[i][j]-'0');
                vx[s[i][j]-'0']=i;
                vy[s[i][j]-'0']=j;
            }
            else if(s[i][j]=='B')
            {
                bx[++bn]=i;
                by[bn]=j;
            }
            else if(s[i][j]=='S')
                sx=i,sy=j,s[i][j]='.';
        }
    }
    for(int i=1;i<=vn;i++)
        scanf("%d",val+i);
}

void develop(int x0,int y0,int vs0,int bs0)
{
    int x,y,vs,bs;
    for(int k=0;k<4;k++)
    {
        x=x0+dx[k],y=y0+dy[k];
        if(s[x][y]=='.')
        {
            vs=vs0,bs=bs0;
            for(int i=1;i<=vn;i++)
                if(x0>vx[i]&&x>vx[i]&&(y0>vy[i])!=(y>vy[i]))vs^=1<<i-1;
            for(int i=1;i<=bn;i++)
                if(x0>bx[i]&&x>bx[i]&&(y0>by[i])!=(y>by[i]))bs^=1<<i-1;
            if(f[x][y][vs][bs]==-1)
            {
                f[x][y][vs][bs]=f[x0][y0][vs0][bs0]+1;
                q[qt=qt+1&L]=state(x,y,vs,bs);
            }
        }
    }
}

int sumval(int st)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        if(st&(1<<i-1))sum+=val[i];
    return sum;
}

void work()
{
    memset(f,-1,sizeof(f));
    f[sx][sy][0][0]=0;
    develop(sx,sy,0,0);
    for(state now;qh<qt;)
    {
        now=q[qh=qh+1&L];
        develop(now.x,now.y,now.vs,now.bs);
    }
    for(int i=0;i<1<<vn;i++)
        if(f[sx][sy][i][0]!=-1)
            ans=max(ans,sumval(i)-f[sx][sy][i][0]);
    printf("%d\n",ans);
}

int main()
{
    init();
    work();
    return 0;
}