#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,m;vector<int> a[o];
inline void slv(){
	int x=0,y=0;
	for(int i=1;i<=n;++i){
		for(int j=1,mx=0;j<=m;mx=max(mx,a[i][j++])) if(a[i][j]<mx) y=j;
		for(int j=m,mn=2e9;j;mn=min(mn,a[i][j--])) if(a[i][j]>mn) x=j;
	}
	if(!x){printf("1 1\n");return;}
	for(int i=1;i<=n;++i){
		swap(a[i][x],a[i][y]);
		for(int j=1;j<m;++j) if(a[i][j]>a[i][j+1]){printf("-1\n");return;}
	}
	printf("%d %d\n",x,y);
}
int main(){
	for(scanf("%d",&T);T--;slv()){
		scanf("%d%d",&n,&m);
		for(int i=1,j;i<=n;++i) for(a[i].resize(m+1),j=1;j<=m;++j) scanf("%d",&a[i][j]);
	}
	return 0;
}