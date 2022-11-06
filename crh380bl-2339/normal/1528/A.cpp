#include<bits/stdc++.h>
#define N 200002
using namespace std;
int L[N],R[N];
long long f[N][2];
vector<int>v[N];
void DFS(int x,int fa){
	int i,y;
	for(i=0;i<v[x].size();++i){
		if(v[x][i]==fa)continue;
		y=v[x][i];
		DFS(y,x);
		f[x][0]+=max(f[y][0]+abs(L[y]-L[x]),f[y][1]+abs(R[y]-L[x]));
		f[x][1]+=max(f[y][0]+abs(L[y]-R[x]),f[y][1]+abs(R[y]-R[x]));
	}
}
int main(){
	int T,n,i,j,m,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d%d",&L[i],&R[i]);
			v[i].clear();
			f[i][0]=f[i][1]=0;
		}
		for(i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		DFS(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
	return 0;
}