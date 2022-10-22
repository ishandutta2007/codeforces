/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f;
const int N=3000;
int n;
vector<pair<int,bool> > nei[N+1];
int cnt1[N+1],cnt2[N+1];
int dfs1(int x,int fa=0){
	int res=0;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i].X,z=nei[x][i].Y;
		if(y==fa)continue;
		res+=dfs1(y,x)+z;
	}
	return res;
}
int dfn[N+1],nowdfn,mxdfn[N+1];
void dfs2(int x=1,int fa=0){
	dfn[x]=mxdfn[x]=++nowdfn;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i].X,z=nei[x][i].Y;
		if(y==fa)continue;
		dfs2(y,x);
		cnt2[x]+=cnt2[y]+z;
		mxdfn[x]=mxdfn[y];
	}
}
int ans=inf;
int dp[N+1];
void dfs3(int x=1,int fa=0){
	dp[x]=cnt2[x];
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i].X,z=nei[x][i].Y;
		if(y==fa)continue;
		dfs3(y,x);
		dp[x]=min(dp[x],dp[y]+cnt2[x]-cnt2[y]-z+!z);
	}
}
bool is[N+1];
void dfs4(int x=1,int fa=0){
	int res=inf;
	for(int i=1;i<=n;i++)if(dfn[i]<dfn[x]||dfn[i]>mxdfn[x])res=min(res,cnt1[i]-cnt2[x]-is[x]);
	ans=min(ans,res+dp[x]);
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i].X,z=nei[x][i].Y;
		if(y==fa)continue;
		is[y]=z;
		dfs4(y,x);
	}
}
int main(){
	cin>>n;
	if(n==1)return puts("0"),0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(mp(y,0));nei[y].pb(mp(x,1));
	}
	for(int i=1;i<=n;i++)cnt1[i]=dfs1(i)/*,cout<<cnt1[i]<<"\n"*/;
	dfs2();
//	for(int i=1;i<=n;i++)printf("cnt2[%d]=%d\n",i,cnt2[i]);
	dfs3();
	dfs4();
	cout<<ans;
	return 0;
}