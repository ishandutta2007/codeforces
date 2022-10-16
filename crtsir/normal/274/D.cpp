#include<bits/stdc++.h>
using namespace std;
const int Maxv=200003;
vector<int>G[Maxv],rG[Maxv],vs,b[100003];
vector<pair<int,int> >a[100003];
bool vis[Maxv];
int cmp[Maxv],n,m;
void AE(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
} 
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
		if(!vis[G[x][i]])
			dfs(G[x][i]);
	vs.push_back(x);
}
void rdfs(int x,int k){
	vis[x]=1;
	cmp[x]=k;
	for(int i=0;i<rG[x].size();i++)
		if(!vis[rG[x][i]])
			rdfs(rG[x][i],k);
}
int scc(){
	memset(vis,0,sizeof(vis));vs.clear();
	for(int i=0;i<n;i++)
		if(!vis[i])
			dfs(i);
	memset(vis,0,sizeof(vis));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
		if(!vis[vs[i]])
			rdfs(vs[i],k++);
	return k;
}
bool ccmp(int x,int y){
	return cmp[x]>cmp[y];
}
int ans[100003];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			if(x!=-1)a[i].push_back(make_pair(x,j)); 
			b[i].push_back(x);
		}
	}
	int cntt=m;
	for(int i=0;i<m;i++)ans[i]=i;
	for(int i=0;i<n;i++){
		sort(a[i].begin(),a[i].end());
		sort(b[i].begin(),b[i].end());
		b[i].erase(unique(b[i].begin(),b[i].end()),b[i].end());
		for(int j=1;j<b[i].size();j++)
			AE(cntt+j*2,cntt+j*2-1);//:cntt+2k+1,:cntt+2k 
		int k=0;
		for(int j=0;j<b[i].size();j++)
			for(;k<a[i].size()&&a[i][k].first==b[i][j];k++)
				AE(cntt+j*2+1,a[i][k].second),
				AE(a[i][k].second,cntt+j*2);
		cntt+=b[i].size()*2;
	}
	int tmp=m;
	n=cntt;
	int cnt=scc();
	if(cnt!=cntt){cout<<-1;return 0;}
	sort(ans,ans+tmp,ccmp);
	for(int i=0;i<tmp;i++)cout<<ans[i]+1<<' ';
}