#include<cstdio>
using namespace std;
const int o=1010;
int n,m,t[o],a[o],c1,b[o],c2,ptn[o];bool vis[o];
bool Hungary(int nw){
	for(int i=1;i<=c2;++i) if(a[nw]%b[i]==0&&2ll*a[nw]+b[i]<=m&&!vis[i]){
		vis[i]=1;
		if(!ptn[i]||Hungary(ptn[i])){ptn[i]=nw;return true;}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&t[i]);
		if(t[i]>m/3) a[++c1]=t[i];
		else b[++c2]=t[i];
	}
	for(int i=1;i<=c1;++i){
		for(int j=1;j<=c2;++j) vis[j]=0;
		if(!Hungary(i)){printf("-1");return 0;}
	}
	printf("%d\n",c2);
	for(int i=1;i<=c2;++i)
		if(ptn[i]) printf("%d %d\n",2*a[ptn[i]]+b[i],a[ptn[i]]+b[i]);
		else printf("%d %d\n",3*b[i],2*b[i]);
	return 0;
}