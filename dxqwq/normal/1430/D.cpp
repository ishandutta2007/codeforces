#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char a[1000003];
int b[1000003];
int main()
{
	for(int T=read(); T--;)
	{
		int n=read();
		scanf("%s",a+1);
		int cnt=0,lst=1;
		for(int i=2; i<=n+1; i++) if(a[i]!=a[i-1]) b[++cnt]=lst,lst=1; else ++lst;
		int x=1,y=1,ans=0;
		while(x<=cnt)
		{
			while(y<cnt && b[y]<=1) ++y;
			if(b[y]<=1) ++x; else --b[y];
			++x,++ans;
			y=max(x,y);  
		}
		printf("%d\n",ans);
	}
	return 0;
}