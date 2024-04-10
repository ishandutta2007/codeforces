#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxn 2005
using namespace std;

int n,i,j,k,dep[maxn],cnt[2],t,e[maxn][maxn];

int main(){
	scanf("%d",&n);
	printf("? 1\n"),fflush(stdout);
	for(i=1;i<=n;i++) scanf("%d",&dep[i]),cnt[dep[i]&1]++;
	for(i=1;i<=n;i++) if (dep[i]==1) e[1][i]=e[i][1]=1;
	t=cnt[1]<cnt[0];
	for(i=2;i<=n;i++) if (dep[i]&1^t^1){
		printf("? %d\n",i),fflush(stdout);
		for(j=1;j<=n;j++) {
			scanf("%d",&k);
			if (k==1) e[i][j]=e[j][i]=1;
		}	
	}
	printf("!\n");
	for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) if (e[i][j])
		printf("%d %d\n",i,j);
	fflush(stdout);
}