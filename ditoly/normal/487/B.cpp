#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define N 131072
#define INF 0x3FFFFFFF
int T1[N*2+5],T2[N*2+5],T3[N*2+5];
void CMIN(int*t,int k,int x){for(t[k+=N]=x;k>>=1;)t[k]=min(t[k<<1],t[k<<1|1]);}
int QMIN(int*t,int l,int r)
{
	int res=INF;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=min(res,t[l+1]);
		if( r&1)res=min(res,t[r-1]);
	}
	return res;
}
void CMAX(int*t,int k,int x){for(t[k+=N]=x;k>>=1;)t[k]=max(t[k<<1],t[k<<1|1]);}
int QMAX(int*t,int l,int r)
{
	int res=-INF;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=max(res,t[l+1]);
		if( r&1)res=max(res,t[r-1]);
	}
	return res;
}
int main()
{
	int n,s,l,i,j;
	for(i=1;i<2*N;++i)T1[i]=T3[i]=INF,T2[i]=-INF;
	n=read();s=read();l=read();
	for(i=1;i<=n;++i)j=read(),CMIN(T1,i,j),CMAX(T2,i,j);
	for(CMIN(T3,0,0),i=j=1;i<=n;++i)
	{
		while(QMAX(T2,j,i)-QMIN(T1,j,i)>s)++j;
		if(j-1<=i-l)CMIN(T3,i,QMIN(T3,j-1,i-l)+1);
	}
	l=QMAX(T3,n,n);printf("%d",l>n?-1:l);
}