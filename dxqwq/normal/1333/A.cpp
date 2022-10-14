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
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		if((n&1) && (m&1))
		{
			for(int i=1; i<=n; i++)
			{
				for(int j=1; j<=m; j++) if((i+j)&1) printf("W"); else printf("B");
				printf("\n"); 
			}
		}
		else
		{
			printf("B");
			for(int i=2; i<=m; i++) if((i+1)&1) printf("B"); else printf("W");
			printf("\n");
			for(int i=2; i<=n; i++)
			{
				for(int j=1; j<=m; j++) if((i+j)&1) printf("B"); else printf("W");
				printf("\n"); 
			}
		}
	}
	return 0;
}