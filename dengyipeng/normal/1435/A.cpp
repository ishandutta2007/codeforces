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
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) printf("%d ",((i&1)?1:-1)*a[i^1]);
		printf("\n");
	}
}