// Problem: B. Gluttony
// Contest: Codeforces - Codeforces Round #446 (Div. 1)
// URL: https://codeforces.com/contest/891/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
pair<int,int> p[53];
int ans[53];
signed main()
{
 	int n=read();
 	for(int i=1; i<=n; i++) p[i].second=i,p[i].first=read();   
 	sort(p+1,p+n+1);
 	for(int i=2; i<=n; i++)
 	{
 		ans[p[i].second]=p[i-1].first;
 	}
 	ans[p[1].second]=p[n].first;
 	for(int i=1; i<=n; i++) printf("%lld ",ans[i]);puts("");
	return 0;
}