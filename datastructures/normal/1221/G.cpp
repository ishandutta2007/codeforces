#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n,m,u[10005],v[10005],first[10005],nxt[10005];
int book[10005],col[10005],cnt,d,fg=1;
ll pow_2[10005];
int f[1048576];
int val[1048576];
ll ans;
void dfs(int now){
	for (int i=first[now];i;i=nxt[i]){
		if (col[v[i]]==0){
			col[v[i]]=3-col[now];
			dfs(v[i]);
		}
		else if (col[now]+col[v[i]]!=3)fg=0;
	}
	return;
}
ll dp(){
	if (n==1)return 2;
	ll ans=0;
	int w=n/2;
	for (int i=0;i<(1<<w);i++){
		int fg=1;
		for (int j=1;j<=m;j++)
			if (u[j]<w&&v[j]<w&&(((1<<u[j])&i)+((1<<v[j])&i)==0))fg=0;
		if (fg==0){
			f[i]=-1;
			continue;
		}
		for (int j=1;j<=m;j++){
			if (u[j]<w&&v[j]>=w&&(!(i&(1<<u[j]))))f[i]|=(1<<(v[j]-w));
			if (v[j]<w&&u[j]>=w&&(!(i&(1<<v[j]))))f[i]|=(1<<(u[j]-w));
		}
	}
	for (int i=0;i<(1<<(n-w));i++){
		int fg=1;
		for (int j=1;j<=m;j++)
			if (u[j]>=w&&v[j]>=w&&(((1<<(u[j]-w))&i)+((1<<(v[j]-w))&i)==0))fg=0;
		if (fg==1)val[i]++;
	}
	for (int i=0;i<n-w;i++)
		for (int j=0;j<(1<<(n-w));j++)
			if (!(j&(1<<i)))val[j]+=val[j|(1<<i)];
	for (int i=0;i<(1<<w);i++)
		if (f[i]!=-1)ans+=val[f[i]];
	return ans;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		u[i]--,v[i]--;
		book[u[i]]=book[v[i]]=1;
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	for (int i=0;i<n;i++)
		if (book[i]==0)d++;
	pow_2[0]=1;
	for (int i=1;i<=n;i++)pow_2[i]=pow_2[i-1]*2;
	for (int i=0;i<n;i++){
		if (col[i]!=0)continue;
		cnt++;
		col[i]=1;
		dfs(i);
	}
	ans=(1ll<<n);
	ans-=2*dp();
	ans-=pow_2[cnt];
	ans+=2*pow_2[d];
	ans+=fg*pow_2[cnt];
	if (m==0)ans-=(1ll<<n);
	cout<<ans<<endl;
}