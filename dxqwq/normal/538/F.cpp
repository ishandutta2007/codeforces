#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[200003];
int ans[200003];
signed main()
{	
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=2; i<=n; i++) for(int l=1,r,fa; l<=i-2; l=r+1)
	{
		r=(i-2)/((i-2)/l),fa=(i-2)/l+1;
		if(a[fa]>a[i]) ++ans[l],--ans[r+1];
	}
	for(int i=2; i<=n; i++) if(a[1]>a[i]) ++ans[i-1];
	for(int i=1; i<n; i++) ans[i]+=ans[i-1],printf("%d ",ans[i]);
	return 0;
}