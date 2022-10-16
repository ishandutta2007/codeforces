#include<bits/stdc++.h>
using namespace std;
const int bs=10000019,mod=1000000007,pw2=32768;
int n,dp[15003][1003],k,q,m;
int v[15003],w[15003],s[15003],t[15003],cnt[25003],ans[25003],pw[1003];
vector<int>dat[65536];
void dfs(int x){
	for(int i=0;i<dat[x].size();i++){
		m++;
		int nw=dat[x][i];
		for(int j=0;j<=k;j++)
			dp[m][j]=dp[m-1][j];
		for(int j=w[nw];j<=k;j++)
			dp[m][j]=max(dp[m][j],dp[m-1][j-w[nw]]+v[nw]);
	}
	if(x>=pw2)
		for(int i=1;i<=k;i++)
			ans[x^pw2]=(ans[x^pw2]+1ll*dp[m][i]*pw[i-1])%mod;
	else
		dfs(x<<1),dfs(x<<1|1);
	m-=dat[x].size();
}
void add(int l,int r,int L,int R,int k,int x){
	if(L<=l&&r<=R){dat[k].push_back(x);return;}
	if(L>r||R<l)return;
	add(l,l+r>>1,L,R,k<<1,x);
	add(l+r+1>>1,r,L,R,k<<1|1,x);
}
int main(){
	pw[0]=1;
	for(int i=1;i<1003;i++)
		pw[i]=1ll*pw[i-1]*bs%mod;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d%d",v+i,w+i);
	memset(s,0,sizeof(s));
	memset(t,-1,sizeof(t));
	cin>>q;
	int nwt=0;
	for(int i=1;i<=q;i++){
		int tp;
		scanf("%d",&tp);
		if(tp!=3)nwt++;
		if(tp==1){
			++n;
			scanf("%d%d",v+n,w+n);
			s[n]=nwt;
		}else if(tp==2){
			int idx;
			scanf("%d",&idx);
			t[idx]=nwt-1;
		}else
			cnt[nwt]++;
	} 
	for(int i=1;i<=n;i++)
		if(t[i]==-1)
			t[i]=nwt;
	for(int i=1;i<=n;i++)
		add(0,pw2-1,s[i],t[i],1,i);
	dfs(1);
	for(int i=0;i<=nwt;i++)
		while(cnt[i]--)
			printf("%d\n",ans[i]);
}