#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;

int T,n,m,i,j,k,c[maxn],ans[maxn];
vector<int> d[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		memset(c,0,sizeof(int)*(n+1));
		for(i=1;i<=m;i++){
			d[i].clear();
			scanf("%d",&k);
			for(j=1;j<=k;j++)
				d[i].push_back(0),scanf("%d",&d[i][j-1]);
			if (k==1) 
				c[d[i][0]]++;
		}
		int tp=1;
		for(i=1;i<=n;i++) if (c[i]>(m+1)/2) tp=0;
		if (!tp) {printf("NO\n");continue;}
		for(i=1;i<=m;i++){
			if (d[i].size()==1)
				ans[i]=d[i][0];
			else {
				for(j=0;j<d[i].size();j++)
					if (c[d[i][j]]<(m+1)/2){
						c[d[i][j]]++;
						ans[i]=d[i][j];
						break;
					}
			}
		}
		printf("YES\n");
		for(i=1;i<=m;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}