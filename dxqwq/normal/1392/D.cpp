#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char a[2000003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=0;
		scanf("%s",a+1);
		for(int i=1; i<=n; i++) a[i+n]=a[i];
		bool f=1;
		char tmp=a[1];
		for(int i=2; i<=n; i++) if(a[i]!=tmp) f=0;
		if(f) 
		{
			printf("%d\n",(n-1)/3+1);
			continue;
		}
		int pos=0,now=0;
		for(int i=1; i<n; i++) if(a[i]!=a[n]) { pos=i-1; break; }
		for(int i=1; i<=n; i++) a[i]=a[i+pos];
		for(int i=1; i<=n; i++) 
		{
			if(a[i]!=a[i-1]) ans+=now/3,now=0;
			++now;
		}
		ans+=now/3;
		printf("%d\n",ans);
	}
	return 0;
}