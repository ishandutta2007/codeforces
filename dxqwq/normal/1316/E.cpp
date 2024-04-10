// Problem: CF1316E Team Building
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1316E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int bcnt[128];
struct node
{
	int v[8];
	bool operator<(const node&t)const{return v[0]>t.v[0];}
}a[100003];
int f[100003][128];
signed main()
{
    int n=read(),p=read(),k=read(),t=1<<p;
    for(int i=1; i<t; ++i) for(int j=1; j<t; j<<=1) (i&j)&&(++bcnt[i]);
    for(int i=1; i<=n; ++i) a[i].v[0]=read();
    for(int i=1; i<=n; ++i) for(int j=1; j<=p; ++j) a[i].v[j]=read();
	sort(a+1,a+n+1),memset(f,0xc0,sizeof(f));
	f[0][0]=0;
	for(int i=1; i<=n; ++i) for(int j=0; j<t; ++j) 
	{
		f[i][j]=f[i-1][j]+((i-bcnt[j]<=k)?a[i].v[0]:0);
		for(int k=1,l=1; k<=j; k<<=1,++l) if(j&k)
		f[i][j]=max(f[i][j],f[i-1][j-k]+a[i].v[l]);
	}
	printf("%lld\n",f[n][t-1]);
	return 0;
}