#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 1000005
using namespace std;

int T,n,i,j,k,ans[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		ans[0]=0;
		for(k=1;k<=n;k=n/(n/k)+1)
			ans[++ans[0]]=n/k;
		ans[++ans[0]]=0;
		printf("%d\n",ans[0]);
		for(i=ans[0];i;i--) printf("%d ",ans[i]);
		printf("\n");
	}
}