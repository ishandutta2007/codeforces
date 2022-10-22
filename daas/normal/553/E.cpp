#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const double pi=acos(-1);
const double oo=1e18;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,T,X,dis[101][101],zone[140000],Lim,a[110],b[110],c[110];
double dp[101][40001],p[101][40001],g[101][40001];
struct complex
{
	double x,y; //x+yi
	complex(double _x=0,double _y=0){x=_x,y=_y;}
}wn[140000],mem1[140000],mem2[140000];
complex operator +(complex x,complex y){return complex(x.x+y.x,x.y+y.y);}
complex operator -(complex x,complex y){return complex(x.x-y.x,x.y-y.y);}
complex operator *(complex x,complex y){return complex(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x);}
complex operator /(complex x,int y){return complex(x.x/y,x.y/y);}
void FFT(complex A[],int lim,int flag)
{
	for(int i=0;i<lim;++i)
		if(zone[i]<i)
			swap(A[zone[i]],A[i]);
	for(int len=1;len<lim;len*=2)
		for(int i=0;i<lim;i+=2*len)
			for(int j=0;j<len;++j)
			{
				complex A1=A[i+j],A2=wn[Lim/len*j]*A[i+j+len];
				A[i+j]=A1+A2;
				A[i+j+len]=A1-A2;
			}
	if(!flag)
	{
		for(int i=0;i<lim;++i) A[i]=A[i]/lim;
		reverse(A+1,A+lim);
	}
}
void CDQ(int l,int r)
{
	if(l==T) return;
	if(l==r)
	{
		for(int i=1;i<n;++i) dp[i][l]=oo;
		for(int i=1;i<=m;++i)
		{
			if(a[i]==n) continue;
			dp[a[i]][l]=min(dp[a[i]][l],g[i][l]+c[i]);
		}
		return;
	}
	int mid=(l+r)/2;
	CDQ(mid+1,r);
	int LOG=ceil(log2(r-l)+1),lim=(1<<LOG);
	for(int i=0;i<lim;++i) zone[i]=((zone[i>>1]>>1)|((i&1)<<LOG-1));
	for(int t=1;t<=m;++t)
	{
		if(a[t]==n) continue;
		for(int i=0;i<lim;++i) mem1[i].x=mem1[i].y=mem2[i].x=mem2[i].y=0;
		for(int i=1;i<=r-l;++i) mem1[i-1].x=p[t][i];
		for(int i=mid+1;i<=r;++i) mem2[r-i].x=dp[b[t]][i];
		//for(int i=0;i<=r-l-1;++i) mem[i].x=p[t][i+1];
		//for(int i=0;i<=r-mid-1;++i) mem[i].y=dp[b[t]][r-i];
		FFT(mem1,lim,1);
		FFT(mem2,lim,1);
		for(int i=0;i<lim;++i) mem1[i]=mem1[i]*mem2[i];
		FFT(mem1,lim,0);
		for(int i=l;i<=mid;++i) g[t][i]+=mem1[r-1-i].x;
	}
	CDQ(l,mid);
}
signed main()
{
	n=read(),m=read(),T=read(),X=read();
	Lim=1; while(Lim<2*T+1) Lim<<=1;
	for(int i=0;i<Lim;++i) wn[i]=complex(cos(pi/Lim*i),sin(pi/Lim*i));
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;++i)
	{
		a[i]=read(),b[i]=read(),c[i]=dis[a[i]][b[i]]=read();
		for(int j=1;j<=T;++j) p[i][j]=(double)read()/1e5;//p[i][T-j]=read()/1e5;
	}
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int j=1;j<=n;++j)
		for(int i=1;i<=n;++i)
			for(int k=1;k<=n;++k)
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	for(int i=1;i<=n;++i)
	{
		dp[i][T]=(i==n?0:dis[i][n]+X);
		for(int j=T+1;j<2*T;++j) dp[i][j]=dis[i][n]+X;
	}
	CDQ(0,2*T-1);
	/*for(int i=1;i<=n;++i)
	{
		for(int j=0;j<2*T;++j) printf("%8.3lf",dp[i][j]);
		cout<<endl;
	}*/
	printf("%.10lf\n",dp[1][0]);
	return 0;
}
/*
.   .   .   . . . .   . . .       .       .     .   . . .    . . .     . . .
.   .   .   .     .   .    .    .   .     .   .       .    .       .     .
.   .   .   . . . .   . . .   . . . . .   . .         .    .       .     .
.   .   .   .   .     .       .       .   .   .       .    .       .     .
. .   . .   .     .   .       .       .   .     .   . . .    . . .     . . .
*/