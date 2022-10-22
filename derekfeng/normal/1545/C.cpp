#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int T,a[1003][503],c[503][503],n;
bool v[1003];
vector<int>res;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(v,0,sizeof(v));
		memset(c,0,sizeof(c));
		scanf("%d",&n);res.clear();
		for(int i=1;i<=n+n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),c[a[i][j]][j]++;
		int ans=1;
		for(int i=1;i<=n;i++){
			int cur=-1;
			for(int j=1;j<=n+n;j++)if(!v[j]){
				for(int k=1;k<=n;k++)if(c[a[j][k]][k]==1){cur=j;break;}
				if(cur>0)break;
			}
			if(cur<0){
				ans=(ans+ans)%M;
				cur=1;while(v[cur])cur++;
			}
			v[cur]=1;
			for(int j=1;j<=n+n;j++)if(!v[j]){
				for(int k=1;k<=n;k++)if(a[j][k]==a[cur][k]){v[j]=1;break;}
				if(v[j])for(int k=1;k<=n;k++)c[a[j][k]][k]--;
			}
			for(int j=1;j<=n;j++)c[a[cur][j]][j]--;
			res.push_back(cur);
		}
		printf("%d\n",ans);
		for(auto x:res)printf("%d ",x);puts("");
	}
}