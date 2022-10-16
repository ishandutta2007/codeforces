// 228
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int l[N],r[N];
long long f[N][2];
basic_string<int>g[N]; 
void dfs(int x,int y){
	f[x][0]=f[x][1]=0;
	for(int i:g[x])if(i!=y){
		dfs(i,x);
		f[x][0]+=max(f[i][0]+abs(l[x]-l[i]),f[i][1]+abs(l[x]-r[i]));
			f[x][1]+=max(f[i][0]+abs(r[x]-l[i]),f[i][1]+abs(r[x]-r[i]));
	}
}
int main(){
	int T,n,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i)g[i].clear(),scanf("%d%d",l+i,r+i);
		for(i=1;i<n;++i){
			scanf("%d%d",&j,&k);
			g[j]+=k,g[k]+=j; 
	}
	dfs(1,0);
	cout<<max(f[1][0],f[1][1])<<'\n';
	}
	return 0;
}