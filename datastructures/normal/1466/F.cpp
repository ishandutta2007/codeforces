#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;
int n,m,k,x[5];
int dsu[500005],fg[500005];
int tot,ans[500005];
int qwq;
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)dsu[i]=i,fg[i]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&k);
		for (int j=1;j<=k;j++)scanf("%d",&x[j]);
		if (k==1){
			if (fg[dsu_find(x[1])]==0){
				fg[dsu_find(x[1])]=1;
				ans[++tot]=i;
			}
		}
		else{
			int awa=dsu_find(x[1]),ovo=dsu_find(x[2]);
			if (awa==ovo)continue;
			if (fg[awa]==1&&fg[ovo]==1)continue;
			ans[++tot]=i;
			dsu[awa]=ovo;
			fg[ovo]|=fg[awa];
		}
	}
	qwq=1;
	for (int i=1;i<=tot;i++)qwq=qwq*2%mod;
	cout<<qwq<<' '<<tot<<endl;
	for (int i=1;i<=tot;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}