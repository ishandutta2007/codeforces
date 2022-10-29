#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;

int T,n,i,j,k,a[maxn],b[maxn],A[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); int c1=0,c2=0;
		for(i=1;i<=n;i++) if (i&1) scanf("%d",&a[++c1]);
			else scanf("%d",&b[++c2]);
		sort(a+1,a+1+c1);
		sort(b+1,b+1+c2);
		for(i=1;i<=c1;i++) A[2*i-1]=a[i];
		for(i=1;i<=c2;i++) A[2*i]=b[i];
		int tp=1;
		for(i=1;i<n;i++) if (A[i]>A[i+1]) tp=0;
		if (tp) printf("YES\n"); else printf("NO\n");
	}
}