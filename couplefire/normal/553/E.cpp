#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct comp
{
    double x,y;
    comp(double a=0,double b=0){x=a,y=b;}
    friend comp operator +(const comp &a,const comp &b){return comp(a.x+b.x,a.y+b.y);}
    friend comp operator -(const comp &a,const comp &b){return comp(a.x-b.x,a.y-b.y);}
    friend comp operator *(const comp &a,const comp &b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
};
int lim=1,n,m,t,c,r[65537],dis[55][55],s[105],w[105];
comp A[65537],B[65537],C[65537];
double p[105][40005],ans[55][40005],c1[65537],c2[65537],c3[65537];
vector<int>to[55];
bool inq[55];
double const pi=acos(-1);
void fft(comp *f,int n,int op)
{
    for(int i=1;i<n;i++)if(i<r[i])swap(f[i],f[r[i]]);
    for(int len=2;len<=n;len<<=1)
    {
        int q=len>>1;comp wn=comp(cos(pi/q),op*sin(pi/q));
        for(int i=0;i<n;i+=len)
        {
            comp w=comp{1,0};
            for(int j=i;j<i+q;j++,w=w*wn)
            {
                comp d=w*f[j+q];
                f[j+q]=f[j]-d;
                f[j]=f[j]+d;
            }
        }
    }
    if(op==-1)
        for(int i=0;i<n;i++)f[i]=f[i]*comp(1.0/n,0);
}
queue<int>q;
void mul(double *f,double *g,double *h)
{
    memset(A,0,sizeof(A));memset(B,0,sizeof(B));
    for(int i=0;i<=2*t+1;i++)A[i].x=f[i],B[i].x=g[i];
    fft(A,lim,1);fft(B,lim,1);
    for(int i=0;i<lim;i++)A[i]=A[i]*B[i];
    fft(A,lim,-1);
    for(int i=0;i<=2*t+1;i++)h[i]=A[i].x;
}
void spfa()
{
    q.push(n);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        inq[now]=0;
        for(auto e:to[now])
        {
            int tar=s[e];
            for(int i=0;i<=t;i++)c1[i]=p[e][t+1-i],c2[i]=ans[now][i];
            for(int i=t+1;i<=2*t+1;i++)c2[i]=ans[now][i];
            mul(c1,c2,c3);
            bool flag=0;
            for(int i=0;i<=t;i++)if(c3[t+i+1]+w[e]<ans[tar][i])flag=1,ans[tar][i]=c3[t+i+1]+w[e];
            if(flag&&(!inq[tar]))q.push(tar),inq[tar]=1;
        }
    }
}
int main()
{
    int y,x;
    scanf("%d%d%d%d",&n,&m,&t,&c);
    while(lim<=((t<<1)+1))lim<<=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1e9;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&s[i],&y,&w[i]);
        to[y].pb(i);
        dis[s[i]][y]=min(dis[s[i]][y],w[i]);
        for(int j=1;j<=t;j++)
            scanf("%d",&x),p[i][j]=x/100000.0;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=t+1;j<=2*t+1;j++)
            ans[i][j]=dis[i][n]+c;
    for(int i=1;i<n;i++)
        for(int j=0;j<=t;j++)
            ans[i][j]=1e9;
    for(int i=1;i<lim;i++)r[i]=(r[i>>1]>>1)+((i&1)?(lim>>1):0);
    spfa();
    printf("%.10lf",ans[1][0]);
    return 0;
}