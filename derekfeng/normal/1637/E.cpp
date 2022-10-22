#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,tot,N;
vector<int>t[1005];
map<int,int>id;
int cnt[300005],val[300005];
vector<int>all;
int tg2;
int tg[300005],dfn[300005];
bool cmp(int a,int b){
	return val[a]<val[b];
}
vector<int>g[300004];
void sol(){
	id.clear(),all.clear(),tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(id.find(x)==id.end())id[x]=++tot,val[tot]=x;
		cnt[id[x]]++;
		g[i].clear();
	}
	for(int i=1;i<=tot;i++)all.push_back(cnt[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	N=0;for(auto x:all)tg[x]=N++;
	for(int i=1;i<=tot;i++)t[tg[cnt[i]]].push_back(i);
	for(int i=0;i<N;i++)sort(t[i].begin(),t[i].end(),cmp);
	while(m--){
		int u,v;scanf("%d%d",&u,&v);u=id[u],v=id[v];
		g[u].push_back(v),g[v].push_back(u);
	}
	ll ans=0;
	for(int i=0;i<N;i++)for(auto x:t[i]){
		++tg2;
		for(auto z:g[x])dfn[z]=tg2;
		dfn[x]=tg2;
		for(int j=i;j<N;j++){
			int cur=t[j].size()-1;
			while(cur>=0&&dfn[t[j][cur]]==tg2)cur--;
			if(cur>=0)ans=max(ans,(ll)(all[i]+all[j])*(val[x]+val[t[j][cur]]));
		}
	}
	printf("%lld\n",ans);
	for(int i=0;i<N;i++)t[i].clear();
	for(int i=1;i<=tot;i++)cnt[i]=0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}