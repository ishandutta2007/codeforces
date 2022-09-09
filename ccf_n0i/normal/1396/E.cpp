#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
long long n,m,i,j,rt,sz[100005],dep[100005],fr[100005],lk[100005],par[100005],vis[100005];
vector<long long> e[100005];set<long long> son[100005];
priority_queue<pair<long long,long long> > pq[100005];
priority_queue<pair<long long,long long> > pq2;
vector<long long> v[100005];
void dfs1(long long x,long long fa){
	sz[x]=1;bool f=1;
	int i;for(i=0;i<e[x].size();i++){
		if(e[x][i]==fa) continue;
		dfs1(e[x][i],x);sz[x]+=sz[e[x][i]];
		if(sz[e[x][i]]>n/2)f=0;
	}
	if(n-sz[x]>n/2)f=0;
	if(f) rt=x;
}
void dfs2(long long x,long long fa,long long f){
	fr[x]=f;sz[x]=1;
	int i;for(i=0;i<e[x].size();i++){
		if(e[x][i]==fa) continue;
		par[e[x][i]]=x;
		son[x].insert(e[x][i]);
		dep[e[x][i]]=dep[x]+1;
		dfs2(e[x][i],x,fa?f:e[x][i]);
		sz[x]+=sz[e[x][i]];
	}
	if(f&&!son[x].empty()) pq[f].push(make_pair(dep[x],x));
}
void dfs3(long long x,long long fa,long long f){
	if(f&&!lk[x]) v[f].push_back(x);
	int i;for(i=0;i<e[x].size();i++){
		if(e[x][i]==fa) continue;
		dfs3(e[x][i],x,fa?f:e[x][i]);
	}
}
void solve(int t){
	while(!pq[t].empty()&&(pq[t].top().first>m||vis[pq[t].top().second])){
		pq[t].pop();
	}
	assert(!pq[t].empty());
	int x=pq[t].top().second;pq[t].pop();
	if(son[x].size()>=2){
		int t1=*son[x].begin();son[x].erase(son[x].begin());
		int t2=*son[x].begin();son[x].erase(son[x].begin());
		lk[t1]=t2;lk[t2]=t1;
		if(!son[x].empty()) pq[t].push(make_pair(dep[x],x));
	}
	else{
		int t1=*son[x].begin();son[x].erase(son[x].begin());
		lk[t1]=x;lk[x]=t1;
		son[par[x]].erase(x);
		if(son[par[x]].empty()) vis[par[x]]=1;
	}
	sz[t]-=2;m-=dep[x];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	rep(i,n-1){
		long long x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(rt,0,0);
	rep(i,n){
		m-=dep[i];
	}
	m=-m;
	if(m<0||m%2!=0){
		puts("NO");
		return 0;
	}
	m/=2;
	dzd(son[rt],it){
		pq2.push(make_pair(sz[*it],*it));
	}
	while(m){
		if(pq2.empty()){
			puts("NO");
			return 0;
		}
		int t=pq2.top().second;pq2.pop();
		if(sz[t]<2){
			puts("NO");
			return 0;
		}
		solve(t);if(sz[t]) pq2.push(make_pair(sz[t],t));
	}
	dfs3(rt,0,0);
	while(pq2.size()>1){
		int t1=pq2.top().second;pq2.pop();
		int t2=pq2.top().second;pq2.pop();
		sz[t1]--;sz[t2]--;
		lk[v[t1].back()]=v[t2].back();
		lk[v[t2].back()]=v[t1].back();v[t1].pop_back();v[t2].pop_back();
		if(sz[t1]) pq2.push(make_pair(sz[t1],t1));
		if(sz[t2]) pq2.push(make_pair(sz[t2],t2));
	}
	assert(pq2.size()==1);
	int t=v[pq2.top().second][0];
	lk[t]=rt;lk[rt]=t;
	cout<<"YES\n";
	rep(i,n)if(i<lk[i]) cout<<i<<' '<<lk[i]<<endl;
	return 0;
}