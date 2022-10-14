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
int lsh[1000003],l[1000003],r[1000003],cnt;
int ans[1000003],t[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) 
	lsh[++cnt]=l[i]=read(),
	lsh[++cnt]=r[i]=read()+1;
	sort(lsh+1,lsh+cnt+1);
	int len=unique(lsh+1,lsh+cnt+1)-lsh-1;
	for(int i=1; i<=n; i++) 
	l[i]=lower_bound(lsh+1,lsh+len+1,l[i])-lsh,
	r[i]=lower_bound(lsh+1,lsh+len+1,r[i])-lsh;
	for(int i=1; i<=n; i++) ++t[l[i]],--t[r[i]];
	for(int i=1,now=0; i<len; i++) now+=t[i],ans[now]+=lsh[i+1]-lsh[i];
	for(int i=1; i<=n; i++) printf("%lld ",ans[i]);
	puts("");
	return 0;
}