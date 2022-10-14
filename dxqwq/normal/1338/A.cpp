#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
long long a[114514];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1; i<=n; i++) a[i]=readll();
		long long lst=-1234567890;
		int ans=0;
		for(int i=1; i<=n; i++) 
		{
			if(lst<a[i]) 
			{
				lst=a[i];
				continue;
			}
			int cnt=0;
			long long now=1;
			while(a[i]<lst) ++cnt,a[i]+=now,now<<=1;
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}