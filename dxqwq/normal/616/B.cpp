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
int a[103][103];
int mx[103];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) a[i][j]=read();
	for(int i=1; i<=n; i++) mx[i]=a[i][1];
	for(int i=1; i<=n; i++) for(int j=2; j<=m; j++) mx[i]=min(mx[i],a[i][j]);
	int ans=0;
	for(int i=1; i<=n; i++) ans=max(ans,mx[i]);
 	printf("%lld\n",ans);
    return 0;
}