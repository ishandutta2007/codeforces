#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int T,n,i,j,k,a[maxn],ans[2][maxn],c[2];

int main(){
	scanf("%d",&T); 
	while (T--){
		scanf("%d",&n); char ch=getchar();
		while (ch<'0'||ch>'1') ch=getchar();
		for(i=1;i<=n;i++) a[i]=ch-'0',ch=getchar();
		int cnt=0;
		for(i=1;i<=n;i++) cnt+=a[i];
		if ((n&1)||(cnt&1)) {printf("NO\n");continue;}
		int p=0,q=1,tp=0; c[0]=c[1]=0,k=0;
		for(i=1;i<=n;i++) if (a[i]){
			k++; 
			if (k<=cnt/2) c[0]++,c[1]++,ans[0][i]=ans[1][i]=1;
			else c[0]--,c[1]--,ans[0][i]=ans[1][i]=0;
			if (c[0]<0||c[1]<0) tp=1;
		} else {
			if (c[p]>c[q]) swap(p,q);
			c[p]++,c[q]--,ans[p][i]=1,ans[q][i]=0;
			if (c[0]<0||c[1]<0) tp=1;
		}
		if (tp||c[0]||c[1]) printf("NO\n"); else {
			printf("YES\n");
			for(i=1;i<=n;i++) putchar(ans[0][i]?'(':')'); putchar('\n');
			for(i=1;i<=n;i++) putchar(ans[1][i]?'(':')'); putchar('\n');
		}
	}
}