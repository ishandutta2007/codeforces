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
int n;
int a[1000003];
int check(int x)
{
	if(x==1||x==n) return 0;
	if(a[x-1]>a[x]&&a[x]<a[x+1]) return 1;
	if(a[x-1]<a[x]&&a[x]>a[x+1]) return 1;
	return 0;
}
signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1; i<=n; i++) a[i]=read();
		int ans=0;
		for(int i=2; i<n; i++) ans+=check(i);
		int mx=0;
		for(int i=2; i<n; i++) 
		{
			int t=a[i];
			int X=check(i-1)+check(i)+check(i+1);
			a[i]=a[i-1];
			int Y=check(i-1)+check(i)+check(i+1);
			mx=max(mx,X-Y);
			a[i]=a[i+1];
			Y=check(i-1)+check(i)+check(i+1);
			mx=max(mx,X-Y);
			a[i]=t;
		}
		printf("%d\n",ans-mx);
	}
	return 0;
}