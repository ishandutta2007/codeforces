#include<bits/stdc++.h>
using namespace std;
const int N=5+4e5;
char s[N];
int x[N],y[N];
vector<vector<bool> > a;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		memset(x,0,sizeof(int)*(n+1));
		memset(y,0,sizeof(int)*(m+1));
		a.clear(); a.resize(n);
		for(int i=0;i<n;++i){
			scanf("%s",s); a[i].resize(m);
			for(int j=0;j<m;++j){
				if(s[j]=='.') ++x[i],++y[j],a[i][j]=1;
				else a[i][j]=0;
			}
		}
		int ans=1e9;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				ans=min(ans,x[i]+y[j]-a[i][j]);
		printf("%d\n",ans);
	}
	return 0;
}