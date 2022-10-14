#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
double a[10003][1003];
signed main()
{
	int n=read();
	a[0][0]=1.0;
	for(int i=1; i<=10000; i++) for(int j=1; j<=n; j++) a[i][j]=(a[i-1][j-1]*(n-j+1)+a[i-1][j]*j)/n;
	for(int q=read();q--;)
	{
		double x=read()/2000.0;
		for(int i=1,f=1; f; i++) if(a[i][n]>x) printf("%d\n",i),f=0;
	}
	return 0;
}