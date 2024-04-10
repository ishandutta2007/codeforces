// Problem: CF1111D Destroy the Colony
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1111D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[100003];
int cnt[52],t[52][52];
int f[50003],g[50003];
int fac[100003],ifac[100003];
int n,m,S;
void solve(int x,int y)
{
	memcpy(g,f,sizeof(f));
	for(int i=cnt[x]; i<=m; ++i) 
		g[i]=(g[i]+p-g[i-cnt[x]])%p;
	for(int i=cnt[y]; i<=m; ++i) 
		g[i]=(g[i]+p-g[i-cnt[y]])%p;
	for(int i=m; i>=cnt[x]+cnt[y]; --i) 
		g[i]=(g[i]+g[i-cnt[x]-cnt[y]])%p;
	t[x][y]=g[m];
	return ;
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1),m=n>>1;
	fac[0]=ifac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=1; i<=n; ++i) 
		if(s[i]<='Z') ++cnt[s[i]-'A'];
		else ++cnt[s[i]-'a'+26];
	f[0]=1,S=fac[m]*fac[m]%p;
	for(int i=0; i<52; ++i) S=S*ifac[cnt[i]]%p;
	for(int i=0; i<52; ++i) if(cnt[i])
		for(int j=m; j>=cnt[i]; --j) 
			f[j]=(f[j]+1ll*f[j-cnt[i]]%p)%p;
	for(int T=read();T--;)
	{
		int x=read(),y=read();
		if(s[x]<='Z') x=s[x]-'A'; else x=s[x]-'a'+26;
		if(s[y]<='Z') y=s[y]-'A'; else y=s[y]-'a'+26;
		if(x==y) {printf("%lld\n",S*f[m]%p);continue;}
		if(x>y) swap(x,y);
		if(t[x][y]) printf("%lld\n",S*t[x][y]%p);
		else solve(x,y),printf("%lld\n",S*t[x][y]%p); 
	}
	return 0;
}