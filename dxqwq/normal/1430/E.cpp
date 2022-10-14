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
char a[1000003],b[1000003];
int f[1000003];
int tree[1000003];
int n=read();
void add(int x)
{
	while(x<=n) ++tree[x],x+=x&(-x);
	return ;
}
long long sum(int x)
{
	long long res=0;
	while(x) res+=tree[x],x-=x&(-x);
	return res;
}
signed main()
{
	scanf("%s",a+1);
	for(int i=1; i<=n; i++) b[i]=a[n+1-i];
	int p=1,q=1;
	for(char x='a'; x<='z'; x++,p=q=1) while(1) 
	{
		while(p<=n && a[p]!=x) ++p;
		if(p>n) break;
		while(q<=n && b[q]!=x) ++q;
		if(q>n) break;
		f[p]=q;
		++p,++q;
	}
	long long ans=0;
	for(int i=1; i<=n; i++) 
	{
		ans+=sum(n)-sum(f[i]);
		add(f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}