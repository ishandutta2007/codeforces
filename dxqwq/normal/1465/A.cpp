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
char s[1003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),cnt=0;
		scanf("%s",s+1);
		for(int i=1; i<=n; i++) (s[i]==')')?++cnt:cnt=0;
		if(cnt*2>n) puts("Yes");
		else puts("No");
	}
	return 0;
}