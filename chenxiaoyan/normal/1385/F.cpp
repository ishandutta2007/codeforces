/*





D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
void prt(int x){
	if(x>9)prt(x/10);
	putchar(x%10^48);
}
const int N=200000;
int n,m;
vector<int> nei[N+1];
int cnt[N+1];
bool dp0[N+1];
int dp[N+1];
void dfs(int x=1,int fa=0){//DP 
	cnt[x]=0;dp0[x]=true;dp[x]=0;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dfs(y,x);
		cnt[x]+=dp0[y];dp0[x]&=dp0[y];dp[x]+=dp[y];
	}
	dp[x]+=cnt[x]/m;
	dp0[x]&=cnt[x]%m==0;
//	printf("dp[%d]=%d\n",x,dp[x]);
}
int ans;
void dfs0(int x=1,int fa=0){// 
//	printf("%d=%d\n",x,dp[x]);
	ans=max(ans,dp[x]);// 
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		int cnt_x=cnt[x],dp0_x=dp0[x],dp_x=dp[x],cnt_y=cnt[y],dp0_y=dp0[y],dp_y=dp[y];
		cnt[x]-=dp0[y];dp0[x]=cnt[x]==nei[x].size()-1&&cnt[x]%m==0;dp[x]=dp[x]-dp[y]-(cnt[x]+dp0[y])/m+cnt[x]/m;
		cnt[y]+=dp0[x];dp0[y]=cnt[y]==nei[y].size()&&cnt[y]%m==0;dp[y]=dp[y]+dp[x]-(cnt[y]-dp0[x])/m+cnt[y]/m;// 
		dfs0(y,x);
		cnt[x]=cnt_x;dp0[x]=dp0_x;dp[x]=dp_x;cnt[y]=cnt_y;dp0[y]=dp0_y;dp[y]=dp_y;// 
	}
}
void mian(){
	read(n);read(m);
	for(int i=1;i<=n;i++)nei[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		nei[x].pb(y);nei[y].pb(x);
	} 
	dfs();
	ans=0;dfs0();
	prt(ans);putchar('\n');
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}