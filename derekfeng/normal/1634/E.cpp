#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<int>all;
vector<vector<int> >v;
int deg[400004];bool vis[200004];
int cnt,head[400004],id[400004],nxt[400004],to[400004];
int ans[200004];
void ins(int x,int y,int i){
	id[++cnt]=i,to[cnt]=y,nxt[cnt]=head[x],head[x]=cnt;
}
void dfs(int x){
	for(int i=head[x];i;i=head[x]){
		for(;i&&vis[abs(id[i])];i=nxt[i]);head[x]=i;
		if(i)vis[abs(id[i])]=1,dfs(to[i]),ans[abs(id[i])]=id[i];
	}
}
int main(){
	scanf("%d",&m);
	v.push_back({});
	for(int i=0;i<m;i++){
		int n;scanf("%d",&n);
		vector<int>tmp;
		while(n--){
			int x;scanf("%d",&x);
			tmp.push_back(x),all.push_back(x);
		}
		v.push_back(tmp);
	}
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	n=all.size();
	for(auto &V:v)for(auto &x:V)x=lower_bound(all.begin(),all.end(),x)-all.begin()+1;
	int N=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			++N;
			deg[i]++,deg[m+v[i][j]]++;
			ins(i,m+v[i][j],N);
			ins(m+v[i][j],i,-N);
		}
	}
	for(int i=1;i<=m+n;i++)if(deg[i]&1)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=m+n;i++)dfs(i);
	N=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			++N;
			if(ans[N]<0)putchar('L');
			else putchar('R');
		}
		puts("");
	}
}