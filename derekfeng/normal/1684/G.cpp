#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,a[1005];
vector<int>L,R;
vector<int>g[1005];
int mchL[1005],mchR[1005];
bool vis[1005];
vector<pii>ans;
bool dfs(int x){
	for(auto to:g[x])if(!vis[to]){
		vis[to]=1;
		if(mchR[to]<0||dfs(mchR[to])){
			mchR[to]=x,mchL[x]=to;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]>m/3)R.push_back(a[i]);
		else L.push_back(a[i]);
	}
	for(int i=0;i<L.size();i++)
		for(int j=0;j<R.size();j++)
			if(R[j]%L[i]==0&&L[i]+R[j]*2<=m)g[i].push_back(j);
	int cnt=0;
	memset(mchL,-1,sizeof(mchL)),memset(mchR,-1,sizeof(mchR));
	for(int i=0;i<L.size();i++)
		memset(vis,0,sizeof(vis)),cnt+=dfs(i);
	if(cnt<R.size())return puts("-1"),0;
	for(int i=0;i<L.size();i++){
		if(mchL[i]<0)ans.push_back({3*L[i],2*L[i]});
		else ans.push_back({L[i]+R[mchL[i]]*2,L[i]+R[mchL[i]]});
	}
	printf("%d\n",ans.size());
	for(auto [u,v]:ans)printf("%d %d\n",u,v);
}