// Problem: E1. Abnormal Permutation Pairs (easy version)
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/E1
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int g[503][130003],gg[503][130003];
void init(int n)
{
    g[1][0]=1;
    for(int i=2; i<=n; i++)
    {
        int sum=0;
        for(int j=0; j<=i*(i-1)/2; j++)
        {
            (sum+=g[i-1][j])%=p,g[i][j]=sum;
            if(j>=i-1)
            (((sum-=g[i-1][j-i+1])%=p)+=p)%=p;
        }
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=130000; ++j)
        g[i][j]=(g[i][j]+g[i][j-1])%p;        
        gg[i][0]=1;
        for(int j=1; j<=130000; ++j)
        gg[i][j]=(g[i][j]+gg[i][j-1])%p;
    }
	return ;
}
// int F(int x)
// {
	// int res=0;
	// for(int i=0; i<=x*(x-1)/2; ++i) 
	// for(int y=2; y<=x+1&&i+y<=x*(x-1)/2; ++y)
	// {
		// if(x==3)
		// for(int k=1; k<=(x-y+2); ++k) printf("* %d ",i+y);
		// puts("");
		// res=(1ll*g[x][i]*f[x][i+y]%p*(x-y+2)%p+res)%p;
	// }
	// return res;
// }
int Get(int x,int L,int R)
{
	int A=(gg[x][R]+p-gg[x][L-1])%p;
	int B=1ll*g[x][L-1]*(R-L+1)%p;
	return (A+p-B)%p;
}
int F(int x)
{
	int res=0;
	for(int i=0; i<=x*(x-1)/2; ++i) 
	// for(int y=2; y<=x+1; ++y)
		res=(1ll*g[x][i]*Get(x,i+2,i+x+1)%p+res)%p;
	return res;
}
int A[100003];
signed main()
{
	int n=read();
	p=read();
	A[0]=1;
	for(int i=n,j=1; j<=n; ++j,--i) A[j]=1ll*A[j-1]*i%p;
	if(p==1) puts("0"),exit(0);
	int ans=0;
	init(n-1);
	for(int i=2; i<=n; ++i)//position i is different
		ans=(1ll*F(i-1)*A[n-i]%p+ans)%p;
	printf("%d\n",ans);
	return 0;
}