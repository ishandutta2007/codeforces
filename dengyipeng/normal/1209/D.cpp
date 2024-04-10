#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;

int n,m,i,j,k,x,y,fa[maxn];

int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}

void link(int x,int y){
	x=father(x);
	y=father(y);
	if (x!=y) fa[x]=y;
}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	int cnt=0;
	for(i=1;i<=n;i++) if (fa[i]==i) cnt++;
	printf("%d",m-(n-cnt));
}