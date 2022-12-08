#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,pa[1000005],num[1000005],size[1000005];
bool d[1000005],flag[1000005];
int find(int x) {
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) pa[i]=i,size[i]=1;
	flag[1]=1;
	for(int i=1; i<=m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		int x=find(u),y=find(v);
		d[u]^=1;
		d[v]^=1;
		if(x!=y) {
			if(size[x]>size[y])swap(x,y);
			pa[x]=y;
		}
		flag[y]=1;
	}
	int rest=0;
	for(int i=1; i<=n; i++)
		if(i==find(i)&&flag[find(i)])
			rest++;
	if(!flag[find(1)])rest++;
	for(int i=1; i<=n; i++)
		if(d[i])num[find(i)]++;
	if(rest==1) {
		printf("%d\n",num[find(1)]/2);
		return 0;
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(find(i)==i&&flag[i]) {
			ans+=num[i]>>1;
			if(num[i]==0)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}