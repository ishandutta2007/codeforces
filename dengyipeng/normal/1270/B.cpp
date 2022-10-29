#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;

int T,n,i,j,k,mx,mi,l,tp,a[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		tp=0;
		for(i=2;i<=n;i++) {
			if (abs(a[i]-a[i-1])>=2){
				tp=1;
				printf("YES\n%d %d\n",i-1,i);
				break;
			}
		}
		if (!tp) printf("NO\n");
	}
}