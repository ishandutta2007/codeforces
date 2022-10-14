#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[400005],ans=1e9;
signed main()
{
	int n=read(),m=read()<<3,k=m/n;
	for(int i=1; i<=n; i++) a[i]=read();
	if(k>30 || (1<<k)>=n) return 0&puts("0");
	sort(a+1,a+n+1);
	for(int i=1,j=1,cnt=1; i<=n; i++)
	{
		while(j<=n && cnt<=1<<k)
		{
			if(j<n && a[j+1]!=a[j]) ++cnt;
			++j;
		}
		ans=min(ans,i-j+n);
		if(a[i+1]!=a[i]) --cnt;
	}
	printf("%lld",ans);
	return 0;
}