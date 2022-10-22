#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5,INF=(int)1e9;
vector<int> son[N];
int f[N][2],a[N];
void dfs1(int x,int pre){
	if(pre!=0) son[x].erase(find(son[x].begin(),son[x].end(),pre));
	for(auto y:son[x])
		dfs1(y,x);
}
bool cmp(int x,int y){ return x>y; }
bool dfs(int x,int std){
	vector<int> g[2];
	g[0]=g[1]=vector<int>({0,0});
	for(auto y:son[x]){
		if(!dfs(y,std)) return false;
		g[0].push_back(min(f[y][0],f[y][1]+1));
		sort(g[0].begin(),g[0].end(),cmp);
		g[0].pop_back();
		g[1].push_back(min(f[y][0]+1,f[y][1]));
		sort(g[1].begin(),g[1].end(),cmp);
		g[1].pop_back();
	}
	reverse(g[0].begin(),g[0].end());
	reverse(g[1].begin(),g[1].end());
	f[x][0]=f[x][1]=INF;
	bool flag0=g[0][0]+g[0][1]<=std,flag1=g[1][0]+g[1][1]<=std;
	if(a[x]==1){
		if(!flag0) return false;
		f[x][0]=g[0][1];
	}else if(a[x]==2){
		if(!flag1) return false;
		f[x][1]=g[1][1];
	}else{
		if(!flag0&&!flag1) return false;
		if(flag0) f[x][0]=g[0][1];
		if(flag1) f[x][1]=g[1][1];
	}
	return true;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			son[i].clear();
		}
		for(int i=1;i<n;++i){
			int x,y; scanf("%d%d",&x,&y);
			son[x].push_back(y);
			son[y].push_back(x);
		}
		dfs1(1,0);
		int left=0,right=n;
		while(left<right){
			int mid=left+right>>1;
			if(dfs(1,mid)) right=mid;
			else left=mid+1;
		}
		printf("%d\n",right+3>>1);
	}
	return 0;
}