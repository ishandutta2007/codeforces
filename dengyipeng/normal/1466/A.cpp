#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 51
using namespace std;

int T,n,i,j,k,a[maxn],bz[maxn],ans;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n),ans=0;
		memset(bz,0,sizeof(bz));
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) for(j=i+1;j<=n;j++)
			if (!bz[a[j]-a[i]])
				bz[a[j]-a[i]]=1,ans++;
		printf("%d\n",ans);
	}
}