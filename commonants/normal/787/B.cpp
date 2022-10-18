#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n,m;int vis[20011];
int main(){
	int flg=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int k;scanf("%d",&k);
		memset(vis,0,sizeof(int)*(n*2+2));
		int ans=0;
		for(int i=1;i<=k;i++){
			int x;scanf("%d",&x);
			if(ans)continue;
			if(vis[n-x])ans=1;
			vis[x+n]=1;
		}
		if(!ans)flg=1;
	}
	if(flg)printf("YES\n");else printf("NO\n");
	return 0;
}