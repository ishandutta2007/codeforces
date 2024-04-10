#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int T,s,n,m,i,j,k,mx1,mx2;

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&s,&n,&m);
		mx1=mx2=0;
		for(i=1;i<=n;i++) scanf("%d",&k),mx1=max(mx1,k);
		for(i=1;i<=m;i++) scanf("%d",&k),mx2=max(mx2,k);
		if (mx1>mx2) printf("YES\n"); else printf("NO\n");
	}
}