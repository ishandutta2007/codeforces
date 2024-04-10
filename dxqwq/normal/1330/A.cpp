#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[10003];
int main()
{
	int t=read();
	while(t--)
	{
		a[0]=-1;
		int n=read(),k=read(),cnt=0;
		for(int i=1; i<=n; i++) a[i]=read();
		bool f=0;
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++) 
		{
			if(a[i]!=a[i-1]) cnt++;
			if(cnt+k<a[i])
			{
				if(a[i]==a[i-1]) printf("%d\n",cnt+k);else printf("%d\n",cnt+k-1);
				f=1;
				break;
			}
		}
		if(!f) printf("%d\n",cnt+k);
	}
	return 0;
}