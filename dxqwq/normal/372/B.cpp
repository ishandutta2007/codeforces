#include <bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline int get01()
{
	char ch=getchar();
	while((ch&48)!=48) ch=getchar();
	return ch-48;
}
int a[43][43],cnt[43][43][43][43];
int s[43][43],sum[43][43][43][43];
int main()
{
    int n=read(),m=read(),T=read();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) a[i][j]=get01(),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    for(int i=n; i>=1; i--) for(int j=m; j>=1; j--) for(int k=i; k<=n; k++) for(int l=j; l<=m; l++) cnt[i][j][k][l]=cnt[i][j][k-1][l]+cnt[i][j][k][l-1]-cnt[i][j][k-1][l-1]+(s[k][l]-s[k][j-1]-s[i-1][l]+s[i-1][j-1]==0);
    for(int i=n; i>=1; i--) for(int j=m; j>=1; j--) for(int k=i; k<=n; k++) for(int l=j; l<=m; l++) sum[i][j][k][l]=sum[i+1][j][k][l]+sum[i][j+1][k][l]-sum[i+1][j+1][k][l]+cnt[i][j][k][l];
    for(int a,b,c,d; T--;) a=read(),b=read(),c=read(),d=read(),printf("%d\n",sum[a][b][c][d]);
    return 0;
}