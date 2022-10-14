#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long f[1003][1003];
bool vis[1003][1003];
int a[1000003];
vector<int> v[1000003];
long long dfs(int l,int r)
{
	if(l>r) return 1;
	if(vis[l][r]) return f[l][r];
	vis[l][r]=1;
	long long ans1=0,ans2=0;
	int now=l;
	for(int i=l; i<=r; i++) if(a[i]<a[now]) now=i;
	int p=v[a[now]][0],q=v[a[now]].back();
	for(int i=l; i<=p; i++) ans1+=dfs(l,i-1)*dfs(i,p-1)%998244353LL,ans1%=998244353LL;
	for(int i=q; i<=r; i++) ans2+=dfs(q+1,i)*dfs(i+1,r)%998244353LL,ans2%=998244353LL;
	long long ans=ans1*ans2%998244353LL;
	for(int i=0; i+1<v[a[now]].size(); i++) ans*=dfs(v[a[now]][i]+1,v[a[now]][i+1]-1),ans%=998244353LL;
	return f[l][r]=ans;
}
int main()
{
	int m=read(),n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	n=unique(a+1,a+n+1)-a-1;
	if(n>2*m) return 0&puts("0");
	for(int i=1; i<=n; i++) v[a[i]].push_back(i);
	printf("%lld\n",dfs(1,n));
	return 0;
}