#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int dep[N];
vector<int> g[N];
int lft[N],rgt[N],cnt;
int fa[N];
void dfs(int u,int last){
	dep[u]=dep[last]+1;
	fa[u]=last;
	lft[u]=++cnt;
	for(auto v:g[u]){
		if(v==last) continue;
		dfs(v,u);
	}
	rgt[u]=cnt;
}
bool cmp(const int &x,const int &y){
	return lft[x]<lft[y];
}
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int rt=1;
	while(g[rt].size()==1) rt++;
	dfs(rt,0);
	bool flag=0;
	int pre=-1;
	for(i=1;i<=n;i++){
		if(lft[i]==rgt[i]){
			if((dep[i]&1)!=pre&&pre!=-1) flag=1;
			else pre=dep[i]&1;
		}
	}
	int ans=n-1;
	for(i=1;i<=n;i++){
		int sum=0;
		for(auto v:g[i])
			sum+=(lft[v]==rgt[v]);
		if(sum) ans-=(sum-1);
	}
	if(flag) cout<<"3 "<<ans;
	else cout<<"1 "<<ans;
	return 0;
}