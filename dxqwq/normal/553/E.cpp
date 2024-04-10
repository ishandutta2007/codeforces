// Problem: E. Kyoya and Train
// Contest: Codeforces - Codeforces Round #309 (Div. 1)
// URL: https://codeforces.com/problemset/problem/553/E
// Memory Limit: 512 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const double pi=acos(-1);
struct cp
{
    double r,i;
    cp operator+(const cp &x)const{return (cp){x.r+r,x.i+i};}
    cp operator-(const cp &x)const{return (cp){r-x.r,i-x.i};}
    cp operator*(const cp &x)const{return (cp){r*x.r-i*x.i,r*x.i+i*x.r};}
}p[103][65536],tmp[65536];
double a[103][65536];
int dis[103];
int u[103],v[103],w[103];
int rev[65536],N=1;
void init()
{
	rev[0]=0,rev[1]=N>>1;
	for(int i=2,t=N>>2; i<N; i<<=1,t>>=1)
		for(int j=0; j<i; ++j) rev[i+j]=rev[j]|t;
}
void FFT(cp* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) swap(F[i],F[rev[i]]);
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        cp w=(cp){cos(pi/M*op),sin(pi/M*op)};
        for(int l=0,r=len-1; l<=N; l+=len,r+=len)
        {
            cp w0=(cp){1,0};
            for(int i=l; i<l+M; ++i)
            {
                cp x=F[i]+w0*F[i+M],y=F[i]-w0*F[i+M];
                F[i]=x,F[i+M]=y,w0=w0*w;
            }
        }
    }
}
bool inq[103];
vector<int> e[103];
signed main()
{
	int n=read(),m=read(),t=read(),x=read();
	for(N=1;N<=t*3;N<<=1);
	init();
	memset(dis,0x3f,sizeof(dis)),dis[n]=0;
	for(int i=1; i<=m; ++i)
	{
		u[i]=read(),v[i]=read(),w[i]=read(),e[v[i]].push_back(i);
		for(int j=1; j<=t; ++j) p[i][t-j].r=read()/100000.0;
		FFT(p[i],1);
	}
	for(int T=1; T<=n; ++T)
		for(int i=1; i<=m; ++i)
			dis[u[i]]=min(dis[u[i]],dis[v[i]]+w[i]);
	for(int i=1; i<n; ++i)
		for(int j=0; j<=t*2; ++j)
			a[i][j]=dis[i]+x;
	for(int j=t+1; j<=t*2; ++j) a[n][j]=x;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int x=q.front();
		inq[x]=0,q.pop();
		for(int i:e[x])
		{
			for(int j=0; j<N; ++j) tmp[j].r=a[x][j],tmp[j].i=0;
			FFT(tmp,1);
			for(int j=0; j<N; ++j) tmp[j]=tmp[j]*p[i][j];
			FFT(tmp,-1);
			bool flg=0;
			for(int j=0; j<=t; ++j) (a[u[i]][j]>tmp[j+t].r/N+w[i])&&(a[u[i]][j]=tmp[j+t].r/N+w[i],flg=1);
			if(flg&&!inq[u[i]]) inq[u[i]]=1,q.push(u[i]);
		}
	}
	printf("%.10lf\n",a[1][0]);
	return 0;
}