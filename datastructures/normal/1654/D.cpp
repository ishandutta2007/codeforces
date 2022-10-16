#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define mod 998244353
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
} 
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=1ll*t*t%mod;
	if (p&1)t=1ll*t*a%mod;
	return t; 
}
int inv(int x){
	return Qpow(x,mod-2);
}
int tree[1000005],tag[1000005];
void pushup(int now){
	tree[now]=max(tree[now*2],tree[now*2+1]);
	return;
}
void pushdown(int now){
	tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void update(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
int isp[1000005];
int t,n,u[1000005],v[1000005],x[1000005],y[1000005],first[1000005],nxt[1000005]; 
int sz[1000005],idx,dfn[1000005],dfo[1000005];
vector<int> ins[1000005],del[1000005];
int ans;
void dfs1(int now,int fa){
	++idx;
	dfn[now]=idx;
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs1(v[i],now);
		sz[now]+=sz[v[i]];
		ins[x[i]].push_back(v[i]);
		del[y[i]].push_back(v[i]);
	}
	dfo[now]=idx;
	return;
}
void dfs2(int now,int fa,int qwq){
	ans=(ans+qwq)%mod;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)dfs2(v[i],now,qwq*y[i]%mod*inv(x[i])%mod);
	return;
}
signed main(){
	isp[0]=isp[1]=1;
	for (int i=2;i<=200000;i++){
		if (isp[i]==1)continue;
		for (int j=2*i;j<=200000;j+=i)isp[j]=1;
	}
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<n;i++){
			u[i]=read(),v[i]=read(),x[i]=read(),y[i]=read();
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i],x[i+n]=y[i],y[i+n]=x[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		idx=0;
		dfs1(1,0);
		ans=0;
		int a1=1;
		for (int i=1;i<=n;i++){
			if (isp[i]==1)continue;
			for (int j=i;j<=n;j+=i){
				int x=j,y=0;
				while(x%i==0)x/=i,y++;
				for (int k=0;k<(int)ins[j].size();k++)update(1,1,n,dfn[ins[j][k]],dfo[ins[j][k]],y);
				for (int k=0;k<(int)del[j].size();k++)update(1,1,n,dfn[del[j][k]],dfo[del[j][k]],-y);
			}
			int c=max(0ll,tree[1]);
			a1=a1*Qpow(i,c)%mod;
			for (int j=i;j<=n;j+=i){
				int x=j,y=0;
				while(x%i==0)x/=i,y++;
				for (int k=0;k<(int)ins[j].size();k++)update(1,1,n,dfn[ins[j][k]],dfo[ins[j][k]],-y);
				for (int k=0;k<(int)del[j].size();k++)update(1,1,n,dfn[del[j][k]],dfo[del[j][k]],y);
			}
		}
		dfs2(1,0,a1);
		cout<<ans<<endl;
		for (int i=0;i<=2*n;i++)u[i]=v[i]=x[i]=y[i]=first[i]=nxt[i]=0,ins[i].clear(),del[i].clear();
	}
	return 0;
}