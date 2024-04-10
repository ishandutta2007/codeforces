#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;

int n,i,j,k,a[maxn],tot,ans[maxn][3];

void add(int i,int j,int k){
	tot++,ans[tot][0]=i,ans[tot][1]=j,ans[tot][2]=k;
	int s=a[i]^a[j]^a[k];
	a[i]=a[j]=a[k]=s;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n&1){
		for(i=1;i+2<=n;i+=2) add(i,i+1,i+2);
		for(i=1;i+2<n;i+=2) add(i,i+1,n);
		printf("YES\n%d\n",tot);
		for(i=2;i<=n;i++) if (a[i]!=a[i-1])
			printf("!!");
		for(i=1;i<=tot;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	} else {
		for(i=1;i<=n;i++) k^=a[i];
		if (k) {printf("NO\n");return 0;}
		for(i=1;i+2<=n;i+=2) add(i,i+1,i+2);
		for(i=1;i+2<=n;i+=2) add(i,i+1,n);
		printf("YES\n%d\n",tot);
		for(i=2;i<=n;i++) if (a[i]!=a[i-1])	
			printf("!!");
		for(i=1;i<=tot;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
}