#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t;
int main(){
	scanf("%d",&t);
	while(t--){
		vector<vector<int> >v;
		scanf("%d%d",&n,&m);
		v.resize(m+1);
		for(int i=1;i<=m;i++)v[i].resize(n+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&v[j][i]);
		vector<int>ans;
		for(int i=1;i<=n;i++){
			vector<int>c;c.push_back(0);
			for(int j=1;j<=m;j++)c.push_back(v[j][i]);
			sort(c.begin(),c.end());
			for(int j=1;j<=m;j++)if(v[j][i]!=c[j])ans.push_back(j);
		}
		sort(ans.begin(),ans.end()),ans.erase(unique(ans.begin(),ans.end()),ans.end());
		if(ans.empty()){
			puts("1 1");continue;
		}
		int x=ans[0],y=ans[1];
		swap(v[x],v[y]);
		bool ok=1;
		for(int i=1;i<=n;i++)for(int j=2;j<=m;j++)ok&=v[j][i]>=v[j-1][i];
		if(!ok)puts("-1");
		else printf("%d %d\n",x,y);
	}
}