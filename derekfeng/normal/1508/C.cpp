#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,W,f[200005];
set<int>st,g[200005];
vector<pair<int,pair<int,int> > >vec;
int F(int x){
	return x==f[x]?x:f[x]=F(f[x]);
}
ll cnt,ans;
void merge(int x,int y){
	x=F(x),y=F(y);
	if(x==y)return;
	f[y]=x;
}
void dfs(int x){
	st.erase(x);
	for(auto it=st.begin();it!=st.end();){
		int to=(*it);
		if(!g[x].count(to)){
			--cnt;
			merge(x,to);
			dfs(to);
		}
		it=st.upper_bound(to);
	}
}
int ff[200005];
int FF(int x){
	return x==ff[x]?x:ff[x]=FF(ff[x]);
}
void Merge(int x,int y){
	x=FF(x),y=FF(y);
	if(x==y)return;
	ff[y]=x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);W^=w;
		vec.push_back(make_pair(w,make_pair(u,v)));
		g[u].insert(v),g[v].insert(u);
	}
	for(int i=1;i<=n;i++)st.insert(i),f[i]=ff[i]=i;
	cnt=(ll)n*(n-1)/2-m;
	for(int i=1;i<=n;i++)if(st.count(i))dfs(i);
	if(cnt>0)W=0;
	sort(vec.begin(),vec.end());
	for(auto x:vec){
		int u=x.second.first,v=x.second.second,w=x.first;
		if(F(u)==F(v)){
			if(FF(u)!=FF(v)){
				W=min(W,w);
				Merge(u,v);
			}
		}else ans+=w,merge(u,v),Merge(u,v);
	}
	printf("%I64d",ans+W);
}