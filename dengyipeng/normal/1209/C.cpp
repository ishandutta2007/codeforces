#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;

int T,n,a[maxn],i,d,nx1,nx2,p[maxn],mi[maxn];
char ch;

int main(){
//	freopen("ceshi.in","r",stdin);
//	freopen("ceshi1.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
		for(i=1;i<=n;i++) a[i]=ch-'0',ch=getchar();
		a[n+1]=mi[n+1]=9;
		for(i=n;i>=1;i--) mi[i]=min(mi[i+1],a[i+1]);
		
		int tp=1;
		for(d=0;d<=9;d++){
			nx1=nx2=0;
			for(i=1;i<=n;i++){
				if (a[i]<d||a[i]==d&&mi[i]>=d) {
					if (a[i]<nx1) break;
					nx1=a[i],p[i]=1;
				} else {
					if (a[i]<nx2) break;
					nx2=a[i],p[i]=2;
				}
			}
			if (i>n){
				tp=0;
				for(i=1;i<=n;i++) printf("%d",p[i]);
				printf("\n");
				break;
			}
		}
		if (tp) printf("-\n");
	}
}