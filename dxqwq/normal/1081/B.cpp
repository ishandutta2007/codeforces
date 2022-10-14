// Problem: B. Farewell Party
// Contest: Codeforces - Avito Cool Challenge 2018
// URL: https://codeforces.com/contest/1081/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int cnt[1000003],a[1000003];
int qwq[1000003];
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) a[i]=n-read(),++cnt[a[i]];
	for(int i=1; i<=n; i++)
	{
		if(cnt[i]%i!=0) return puts("Impossible"),0;
	}
	memset(cnt,0,sizeof(cnt));
	int C=0;
	puts("Possible");
	for(int i=1; i<=n; i++) 
	{
		if(qwq[a[i]]==0)
		{
			cnt[a[i]]=++C;
			printf("%d ",C);
		}
		else
		{
			printf("%d ",cnt[a[i]]);
		}
		qwq[a[i]]=(qwq[a[i]]+1)%a[i];
	}
	return 0;
}