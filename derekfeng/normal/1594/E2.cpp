#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int mypow(int x,ll t){
	int ans=1,res=x;
	for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
	return ans;
}
struct node{
	int a[6];
	node(){
		a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=0;
	}
}f[150000];
int n,m,tot=1;
int col[150000];
int s[150000][2];
void dfs(int u,int D){
	if(!s[u][0]&&!s[u][1]){
		ll tmp=(1ll<<D)-2;
		int num=mypow(4,tmp);
		if(col[u]==-1)for(int i=0;i<6;i++)f[u].a[i]=num;
		else f[u].a[col[u]]=num;
		return;
	}
	ll tmp=(1ll<<(D-1))-2;
	int num=mypow(4,tmp);
	node vl,vr;
	if(s[u][0])dfs(s[u][0],D-1),vl=f[s[u][0]];
	else for(int i=0;i<6;i++)vl.a[i]=num;
	if(s[u][1])dfs(s[u][1],D-1),vr=f[s[u][1]];
	else for(int i=0;i<6;i++)vr.a[i]=num;
	int s=0,t=6;
	if(col[u]!=-1)s=col[u],t=col[u]+1;
	for(int i=s;i<t;i++)for(int j=0;j<6;j++)for(int k=0;k<6;k++)
		if(i!=j&&i!=(j+3)%6&&i!=k&&i!=(k+3)%6)
			(f[u].a[i]+=(ll)vl.a[j]*vr.a[k]%M)%=M;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(col,-1,sizeof(col));
	while(m--){
		ll x;scanf("%lld",&x);
		vector<int>v;
		for(;x>1;)v.push_back(x&1),x>>=1;
		reverse(v.begin(),v.end());
		int cur=1;
		for(auto x:v){
			if(!s[cur][x])s[cur][x]=++tot;
			cur=s[cur][x];
		}
		char buf[6];scanf("%s",buf);
		if(buf[0]=='w')col[cur]=0;
		if(buf[0]=='r')col[cur]=1;
		if(buf[0]=='g')col[cur]=2;
		if(buf[0]=='y')col[cur]=3;
		if(buf[0]=='o')col[cur]=4;
		if(buf[0]=='b')col[cur]=5;
	}
	dfs(1,n);
	int ans=0;
	for(int i=0;i<6;i++)(ans+=f[1].a[i])%=M;
	printf("%d",ans);
}