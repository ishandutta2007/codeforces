#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxn 505
using namespace std;

int n,m,i,j,k,f[maxn],g[maxn][2],bz[maxn],d[maxn],ans;

int used[maxn];
void find(vector<int> a){
	if (a.size()==m){
		printf("? ");
		for(int i=0;i<a.size();i++)
			printf("%d ",a[i]);
		printf("\n");
		fflush(stdout);
		scanf("%d",&k),ans^=k;
		return;
	}
	int x=a.size();
	memset(used,0,sizeof(int)*(n+1));
	for(int i=0;i<a.size();i++) used[a[i]]=1;
	vector<int> P,Q;
	int u=g[x][0],v=g[x][1],w=(u+v-x)/2;
	for(int i=0;i<u-w;i++) P.push_back(a[i]);
	for(int i=u-w;i<a.size();i++) Q.push_back(a[i]);
	for(int i=1;i<=n&&w;i++) if (!used[i])
		P.push_back(i),Q.push_back(i),w--;
	find(P),find(Q);
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) f[i]=n+1; f[m]=1,g[m][0]=m;
	for(int now=1;now<=n;now++){
		int x=0;
		for(i=1;i<=n;i++) if (!bz[i]) x=(!x||f[i]<f[x])?i:x;
		if (!x||f[x]>n) break;
		d[++d[0]]=x,bz[x]=1;
		for(i=1;i<=d[0];i++){
			int y=d[i];
			for(k=max(x,y);k<=n&&k<=x+y;k++){
				int z=k*2-x-y;
				if (f[x]+f[y]<f[z])
					f[z]=f[x]+f[y],g[z][0]=x,g[z][1]=y;
			}
		}
	}
	if (f[n]>n) printf("-1"),exit(0);
	vector<int> p;
	for(i=1;i<=n;i++) p.push_back(i);
	find(p);
	printf("! %d\n",ans);
}