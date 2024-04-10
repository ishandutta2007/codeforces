#include<bits/stdc++.h>
using namespace std;
const int N=200005,E=500005,L=1000,M=1000000007,inv2=(M+1)/2;
int n,a[65],vis[65],f[65],k,m,s[65],pz;
int dp[65][32768],su;
vector<int> p,e[65];
long long ans=1,inv[65],fac[65];
int Find(int x){
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v){
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[x]=y;
}
int dfs(int i,int z,int f){
	if(i==m)
		return 1;
	if(dp[i][f]!=-1)
		return dp[i][f];
	long long as=(z?1ll*z*dfs(i+1,z-1,f):0);
	for(int j=0;j<pz;++j)
		if((s[j]&f)!=s[j]&&(s[j]&f)){
			int ff=f|s[j],zz=z;
			for(int w=0;w<pz;++w)
				if((s[w]&ff)==s[w]&&(s[w]&f)!=s[w])
					++zz;
			as+=dfs(i+1,zz-1,ff);
		}
	return dp[i][f]=as%M;
}
void cal(vector<int> p){
	m=p.size();
	pz=p.size();
	k=0;
	for(int i=0;i<p.size();++i){
		int j;
		for(j=0;j<i;++j)
			if(p[i]%p[j]==0)
				break;
		if(j==i){
			for(int j=i+1;j<p.size();++j)
				if(p[j]%p[i]==0){
					s[j]|=1<<k;
					e[k].push_back(j);
				}
			++k;
		}
	}
	m-=k;
	if(m==0){
		for(int i=0;i<k;++i){
			s[i]=0;
			e[i].clear();
		}
		return;
	}
	memset(dp,-1,sizeof(dp));
	long long sm=0;
	for(int i=0;i<pz;++i)
		if(s[i]){
			int zz=0;
			for(int j=0;j<pz;++j)
				if((s[j]&s[i])==s[j]&&s[j])
					++zz;
			sm+=dfs(1,zz-1,s[i]);
		}
	ans=ans*(sm%M)%M;
	su+=max(0,m-1);
	ans=ans*inv[max(0,m-1)]%M;
	for(int i=0;i<pz;++i){
		s[i]=0;
		e[i].clear();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		vis[a[i]]=1;
	}
	fac[0]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(int i=1;i<=n;++i){
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	for(int i=1;i<=60;++i)
		for(int j=i+1;j<=60;++j)
			if(vis[i]&&vis[j]&&j%i==0)
				uniot(i,j);
	for(int i=1;i<=60;++i){
		p.clear();
		for(int j=1;j<=60;++j)
			if(vis[j]&&Find(j)==i)
				p.push_back(j);
		if(p.size())
			cal(p);
	}
	cout<<ans*fac[su]%M;
}