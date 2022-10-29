#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 105
using namespace std;

int T,n,i,j,k,a[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		int u,v;
		scanf("%d%d%d",&n,&u,&v);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=2;i<=n;i++) if (a[i]!=a[i-1]) break;
		if (i>n) printf("%d\n",min(2*v,u+v)); else {
			for(i=1;i<n;i++) if (abs(a[i]-a[i+1])>1) break;
			if (i<n) printf("0\n"); else printf("%d\n",min(u,v));
		}
	}
}