#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
#define maxm 10000005
using namespace std;

int n,i,j,k,ans;
int tot,t[maxm][2],sz[maxm];

void dg(int x,int c){
	if (sz[x]>=2) ans=max(ans,2+c);
	if (t[x][0]) dg(t[x][0],c+(sz[t[x][1]]>0));
	if (t[x][1]) dg(t[x][1],c+(sz[t[x][0]]>0));
}

int main(){
	scanf("%d",&n),tot=1;
	for(i=1;i<=n;i++){
		int a,x=1; scanf("%d",&a);
		for(k=30;k>=0;k--){
			if (!t[x][a>>k&1]) t[x][a>>k&1]=++tot;
			sz[x]++,x=t[x][a>>k&1];
		}
		sz[x]++;
	}
	dg(1,0);
	printf("%d",n-ans);
}