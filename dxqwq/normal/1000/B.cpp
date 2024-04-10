#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],d[1000003];
int main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	a[++n]=m;
	for(int i=n; i--;) d[i]=a[i+1]-a[i]+d[i+2];
	int ans=d[0];
	d[0]=0;
    for(int i=0; i<n; ++i,d[i]=d[i-1]+(1&i?a[i]-a[i-1]:0)) 
	if(a[i]+1<a[i+1]) ans=max(ans,d[i]+a[i+1]-a[i]-1+d[i+1+(1&i)]);
    printf("%d\n",ans),exit(0);
	return 0;
}