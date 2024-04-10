#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 505
using namespace std;

int n,k,i,j,a,b,ca,cb,x,y;

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d",&n,&k);
	a=b=-1;
	for(i=1;i<=k+1;i++){
		printf("? "); for(j=1;j<=k+1;j++) if (i!=j) printf("%d ",j); printf("\n");
		fflush(stdout);
		scanf("%d %d",&x,&y);
		if (a==-1||a==y) a=y,ca++;
		else b=y,cb++;
	}
	printf("! %d",(a>b)?ca:cb);
}