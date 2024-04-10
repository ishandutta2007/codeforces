#include<bits/stdc++.h>
using namespace std;
int n,p[100005],a[100005];
int deg[100005],mx,turns;
vector<int>v[100005],g[100005];
int b[100005],N;
bool vis[100005],ins[100005];
int sta[100005],SZ;
void dfscir(int x){
	sta[SZ++]=x,ins[x]=1,vis[x]=1;
	if(!vis[p[x]])dfscir(p[x]);
	else if(ins[p[x]]){
		int cur=SZ-1;
		for(;;cur--){
			int u=sta[cur];
			b[N++]=u;if(u==p[x])break;
		}
	}
	SZ--,ins[x]=0;
}
int pa[100005];
void dfstree(int x,int p,int id,int dep){
	pa[dep]=x;
	int bl;
	if(turns<=dep)bl=pa[dep-turns];
	else{
		int T=(turns-dep)%N;
		bl=b[(id+T)%N];
	}
	v[bl].push_back(x);
	for(auto y:g[x])if(y!=p)
		dfstree(y,0,id,dep+1);
}
int h[100005],ans[100005];
set<int>st;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)st.insert(i);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),deg[p[i]]++,g[p[i]].push_back(i);
	int leaves=0;for(int i=1;i<=n;i++)leaves+=deg[i]==0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	turns=(mx-n)/leaves;
	for(int i=1;i<=n;i++)if(!vis[i]){
		N=0,dfscir(i);
		if(N==0)continue;
		reverse(b,b+N);
		for(int j=0;j<N;j++)
			dfstree(b[j],b[(j+N-1)%N],j,0);
	}
	for(int i=1;i<=n;i++)if(a[i]<=n){
		for(auto x:v[i])h[x]=a[i];
		sort(v[i].begin(),v[i].end());
		ans[v[i][0]]=a[i],st.erase(a[i]);
	}
	for(int i=1;i<=n;i++)if(!ans[i]){
		auto it=st.lower_bound(h[i]);
		if(it==st.end())ans[i]=1e9;
		else ans[i]=*it;
		st.erase(ans[i]);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}