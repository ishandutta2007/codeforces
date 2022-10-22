#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define fi first
#define se second
int T,n,m,K,a[5003];
pii dp[5003][5003];
int s[5003],t[5003];
ll f[5003];
ll ans=-1;
void pop(int i,int x){
	while(t[i]>s[i]&&dp[i][s[i]].fi<x)s[i]++;
}
void add(int i,pii x){
	while(t[i]>s[i]&&dp[i][t[i]-1].se<=x.se)t[i]--;
	dp[i][t[i]++]=x;
}
int main(){
	scanf("%d%d%d",&n,&K,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=m;i++)s[i]=t[i]=0;
	add(0,{0,0});
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=-1e18;
			pop(j-1,i-K);
			if(s[j-1]<t[j-1])f[j]=dp[j-1][s[j-1]].se+a[i];
		}
		for(int j=1;j<=m;j++)add(j,{i,f[j]});
		if(i+K-1>=n)ans=max(ans,f[m]);
	}
	if(ans<0)puts("-1");
	else printf("%I64d",ans);
}