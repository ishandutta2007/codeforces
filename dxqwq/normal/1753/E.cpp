// Problem: E. N Machines
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> v[103],p[103];
int a[103],s[103],sum[103];
bool flg[103];
int n=read(),A=read(),X=read(),Y=read(),m=1,ans=0;
double SDT=clock();
int cases=0;
void chk(int mx)
{
	++cases;
	if((clock()-SDT)/CLOCKS_PER_SEC>0.7)
		puts("Nearly TLE!"),
		printf("Done %d cases\n",cases),exit(0); 
	for(int i=1; i<=m; ++i) s[i]=1;
	for(int i=1; i<=m; ++i)
		if(flg[i]) s[m]*=a[i];
		else s[i]*=a[i];
	for(int i=m-1; i>=1; --i) s[i]*=s[i+1];
	int base=0,R=0;
	for(int i=2; i<=m; ++i) if(s[i]!=s[1]) R+=v[i].size();
	mx=min(mx,R);
	for(int i=1; i<=m; ++i) base+=sum[i]*s[i];
	int l=0,r=1e18,fin=0;
	while(l<=r)
	{
		int mid=(l+r)>>1,tgt=mx;
		for(int i=2; i<=m; ++i) if(s[i]!=s[1])
		{
			int d=mid/(s[1]-s[i]),
			pos=min(lower_bound(v[i].begin(),v[i].end(),-d)-v[i].begin(),tgt);
			tgt-=pos;
		}
		if(tgt==0) fin=mid,l=mid+1;
		else r=mid-1;
	}
	int mid=fin+1,tgt=mx;
	for(int i=2; i<=m; ++i) if(s[i]!=s[1])
	{
		int d=mid/(s[1]-s[i]),
		pos=min(lower_bound(v[i].begin(),v[i].end(),-d)-v[i].begin(),tgt);
		if(pos) tgt-=pos,base+=p[i][pos-1]*(s[1]-s[i]);
	}
	base+=tgt*(fin+1),ans=max(ans,base);
	return ;
}
void dfs(int x,int d=0,int k=0)
{
	if((clock()-SDT)/CLOCKS_PER_SEC>0.7)
		puts("Nearly TLE!"),exit(0); 
	if(A<Y*d) return ;
	if(x>=m) return chk((A-Y*d)/X);
	flg[x]=0,dfs(x+1,d,max(k,a[x]));
	if(k<a[x]) flg[x]=1,dfs(x+1,d+1,k);
	return ;
}
signed main()
{
	v[1].push_back(1);
	for(int i=1; i<=n; ++i)
	{
		char c=getchar();
		while(c!='*'&&c!='+') c=getchar();
		int x=read();
		if(c=='+') v[m].push_back(x);
		else if(x!=1) a[m++]=x;
	}
	for(int i=1; i<=m; ++i)
	{
		sort(v[i].begin(),v[i].end()),
		reverse(v[i].begin(),v[i].end());
		for(int &j:v[i])
			sum[i]+=j,j=-j,p[i].push_back(sum[i]);
	}
	a[m]=1,dfs(1),printf("%lld\n",ans);
	return 0;
}