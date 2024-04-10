#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read(),p=read(),q=read();
		int t;
		if(p<q) t=q-1; else t=n-q;
		--t;
		int x=min(abs(p-q)-1,m);
		for(int i=1; i<=m; i++) a[i]=read();
		sort(a+1,a+m+1);
		int ans=0,l=1,r=x;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			bool F=1;
			for(int i=1; i<=mid; i++) if(t-mid+i<a[i]) F=0;	
			if(F==1) ans=mid,l=mid+1; else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}