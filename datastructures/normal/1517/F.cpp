#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define int long long
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
int n,u[1005],v[1005],first[1005],nxt[1005];
int d,f[305][305],g[305][305],f1[305],sf1[305],g1[305],sg1[305],f2[305],sf2[305],g2[305],sg2[305];
int ans[305],sum;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
}
int sufg1(int x){
	int ans=sg1[n];
	if (x>0)upd(ans,mod-sg1[x-1]);
	return ans;
}
int sufg2(int x){
	int ans=sg2[n];
	if (x>0)upd(ans,mod-sg2[x-1]);
	return ans;
}
void dfs(int now,int fa){
	f[now][0]=g[now][0]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
		for (int j=0;j<=n;j++){
			f1[j]=f[now][j],g1[j]=g[now][j];
			if (j==0)f2[j]=g2[j]=0;
			else f2[j]=f[v[i]][j-1],g2[j]=g[v[i]][j-1];
			sf1[j]=f1[j],sg1[j]=g1[j],sf2[j]=f2[j],sg2[j]=g2[j];
			if (j>0)upd(sf1[j],sf1[j-1]),upd(sg1[j],sg1[j-1]),upd(sf2[j],sf2[j-1]),upd(sg2[j],sg2[j-1]);
		}
		memset(f[now],0,sizeof(f[now]));
		memset(g[now],0,sizeof(g[now]));
		for (int j=0;j<=n;j++){
			f[now][j]+=f1[j]*sf2[j]+f2[j]*sf1[j]-f1[j]*f2[j];
			g[now][j]+=g1[j]*sufg2(j)+g2[j]*sufg1(j)-g1[j]*g2[j];
			if (j<=d)g[now][j]+=g1[j]*sf2[d-j]+g2[j]*sf1[d-j];
			f[now][j]+=f1[j]*sufg2(max(0ll,d+1-j))+f2[j]*sufg1(max(0ll,d+1-j));
			f[now][j]%=mod,g[now][j]%=mod;
			if (f[now][j]<0)f[now][j]+=mod;
			if (g[now][j]<0)g[now][j]+=mod;
		}
	}
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=1;i<=n;i++){
		d=i;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		dfs(1,0);
		for (int j=0;j<=n;j++)ans[i]+=g[1][j];
		ans[i]=(ans[i]-1)%mod;
	}
	for (int i=0;i<n;i++)ans[i]=(ans[i+1]+mod-ans[i])%mod,sum=(sum+i*ans[i])%mod;
	sum=(sum+n-1)%mod;
	cout<<sum*Qpow((mod+1)/2,n)%mod<<endl;
	return 0;
}