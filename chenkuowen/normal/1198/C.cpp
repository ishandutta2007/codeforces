#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+5e5;
bool vis[MAX_N];
vector<int> g1,g2;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		g1.clear(); g2.clear();
		memset(vis,0,sizeof(bool)*(3*n+1));
		for(int i=1;i<=m;++i){
			int x,y; scanf("%d%d",&x,&y);
			if(!vis[x]&&!vis[y]){
				g1.push_back(i);
				vis[x]=vis[y]=1;
			}
		}
		for(int i=1;i<=3*n;++i)
			if(!vis[i]) g2.push_back(i);
		if(g1.size()>=n){
			puts("Matching");
			for(int i=0;i<n;++i) printf("%d ",g1[i]);
			puts("");
		}else{
			puts("IndSet");
			for(int i=0;i<n;++i) printf("%d ",g2[i]);
			puts("");
		}
	}
	return 0;
}