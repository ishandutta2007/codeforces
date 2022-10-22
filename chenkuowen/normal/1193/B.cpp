#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+1e5;
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){ memset(head,-1,sizeof(head)); top=-1; }
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
int d[MAX_N],w[MAX_N];
set<pair<int,ll> > a[MAX_N];
void merge1(set<pair<int,ll> >& a,set<pair<int,ll> >& b){
	if(a.size()>b.size()) swap(a,b);
	for(auto i:a){
		auto it=b.lower_bound(make_pair(i.first,0));
		ll key=i.second;
		if(it!=b.end()&&it->first==i.first){
			key+=it->second;
			b.erase(it);
		}
		b.insert(make_pair(i.first,key));
	}
}
void dfs(int x,int pre){
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x);
			merge1(a[y],a[x]);
		}
	}
	if(d[x]!=0){
		auto it=a[x].lower_bound(make_pair(d[x],0));
		ll key=w[x],sum=0;
		if(it!=a[x].end()&&d[x]==it->first){
			key+=it->second;
			a[x].erase(it);
		}
		a[x].insert(make_pair(d[x],key));
		it=a[x].lower_bound(make_pair(d[x],key));
		++it;
		while(1){
			if(it==a[x].end()) break;
			sum+=it->second;
			if(sum>w[x]){
				pair<int,ll> key(it->first,sum-w[x]);
				a[x].erase(it);
				a[x].insert(key);
				break;
			}else{
				auto it1=it; ++it1; 
				a[x].erase(it); it=it1;
			}
		}
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;++i){
		int x; scanf("%d",&x);
		G.add(x,i);
	}
	for(int i=1;i<=m;++i){
		int v; scanf("%d",&v);
		scanf("%d%d",&d[v],&w[v]);
	}
	dfs(1,0);
	ll sum=0;
	for(auto i:a[1]) sum+=i.second;
	printf("%lld\n",sum);
	return 0;
}