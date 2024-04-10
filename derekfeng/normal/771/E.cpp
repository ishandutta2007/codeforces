#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int T,n;
int a[2][300004];
ll sum[3][300004];
int pre[3][300004];
map<ll,int>mp;
void get_trans(int id){
	mp.clear(),mp[0]=0,pre[id][0]=-1;
	for(int i=1;i<=n;i++){
		pre[id][i]=-1;
		ll S=sum[id][i];
		if(mp.find(S)!=mp.end())pre[id][i]=mp[S];
		mp[S]=i;
	}
	for(int i=1;i<=n;i++)
		if(pre[id][i]<pre[id][i-1])pre[id][i]=pre[id][i-1];
}
map<pair<int,int>,ll>dp;
ll getdp(int x,int y){
	if(x==-1||y==-1)return -1e9;
	if(x==0&&y==0)return 0;
	if(dp.find(make_pair(x,y))!=dp.end())return dp[make_pair(x,y)];
	ll &ret=dp[make_pair(x,y)];
	ret=0;
	if(x>=y)ret=max(ret,getdp(pre[0][x],y)+1);
	if(x<=y)ret=max(ret,getdp(x,pre[1][y])+1);
	if(x==y)ret=max(ret,getdp(pre[2][x],pre[2][x])+1);
	else ret=max(ret,getdp(min(x,y),min(x,y)));
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		sum[0][i]=sum[0][i-1]+a[0][i];
		sum[1][i]=sum[1][i-1]+a[1][i];
		sum[2][i]=sum[2][i-1]+a[0][i]+a[1][i];
	}
	for(int i=0;i<3;i++)get_trans(i);
	printf("%d\n",getdp(n,n));
}