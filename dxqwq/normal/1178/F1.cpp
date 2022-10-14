#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long f[503][503];
int a[503];
long long dfs(int l,int r)
{
	if(f[l][r]) return f[l][r];
	if(l>=r) return 1;
	long long ans1=0,ans2=0;
	int p=l;
	for(int i=l; i<=r; i++) if(a[i]<a[p]) p=i;
	for(int i=l; i<=p; i++) ans1+=dfs(l,i-1)*dfs(i,p-1),ans1%=998244353LL;
	for(int i=p; i<=r; i++) ans2+=dfs(p+1,i)*dfs(i+1,r),ans2%=998244353LL;
	return f[l][r]=(ans1*ans2)%998244353LL;
}
int main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	printf("%lld\n",dfs(1,n));
	return 0;
}