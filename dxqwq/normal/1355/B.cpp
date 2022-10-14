#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n; i++) a[i]=read();
		sort(a+1,a+n+1);
		int qwq=0,ans=0;
		for(int i=1; i<=n; i++)
		{
			++qwq;
			if(qwq>=a[i]) qwq=0,++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}