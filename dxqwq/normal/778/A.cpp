// Problem: A. String Game
// Contest: Codeforces - Codeforces Round #402 (Div. 1)
// URL: https://codeforces.ml/contest/778/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
char s[1000003],t[1000003];
int a[1000003];
int n,m;
bool f[1000003];
bool check(int x)
{
	memset(f,0,sizeof(f));
	for(int i=1; i<=x; i++) f[a[i]]=1;
	int xx=1;
	for(int i=1; i<=n; i++)
	{
		if(!f[i]&&s[i]==t[xx]) ++xx;
		if(xx>m) return 1;
	}
	return 0;
}
signed main()
{
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=1; i<=n; i++) a[i]=read();
    int l=1,r=n,ans=0;
    while(l<=r)
    {
    	int mid=(l+r)>>1;
    	if(check(mid)) ans=mid,l=mid+1;
    	else r=mid-1;
    }
    printf("%d\n",ans);
	return 0;
}