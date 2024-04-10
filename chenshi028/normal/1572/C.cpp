#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int o=3010;
int T,n,a[o],f[o][o];vector<int> vec[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",n-1-f[1][n])){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) vec[i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),vec[a[i]].push_back(i);
		for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) f[i][j]=0;
		for(int i=n;i;--i) for(int j=i;j<=n;++j){
			f[i][j]=f[i+1][j];
			for(int k=vec[a[i]].size();k--;) if(vec[a[i]][k]>i&&vec[a[i]][k]<=j)
				f[i][j]=max(f[i][j],f[i+1][vec[a[i]][k]-1]+f[vec[a[i]][k]][j]+1);
		}
	}
	return 0;
}