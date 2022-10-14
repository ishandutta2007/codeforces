#include<bits/stdc++.h>
#define QWQ int T=read(); while(T--)
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
char s[1000003],ss[1000003];
int main()
{
	QWQ
	{
		int n=read();
		scanf("%s",s+1);
		scanf("%s",ss+1);
		int l=1,r=n,t=n,ans=n;
		bool f=1;
		while(t)
		{
			if(f) if((s[l++]-'0')==(ss[t--]-'0')) ++ans; else printf("");
			else if((s[r--]-'0')!=(ss[t--]-'0')) ++ans; else printf("");
			f^=1;
		}
		printf("%d ",ans);
		l=1,r=n,t=n,f=1;
		while(t)
		{
			if(f) if((s[l++]-'0')==(ss[t--]-'0')) printf("1 "); else printf("");
			else if((s[r--]-'0')!=(ss[t--]-'0')) printf("1 "); else printf("");
			printf("%d ",t+1); 
			f^=1;
		}
		puts("");
	}
	return 0;
}