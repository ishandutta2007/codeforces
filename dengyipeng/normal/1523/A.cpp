#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 1005
using namespace std;

int T,n,m,i,j,k,a[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		char ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		for(i=1;i<=n;i++) a[i]=ch-'0',ch=getchar();
		for(i=1;i<=n;i++) if (!a[i]){
			j=i; while (j<n&&a[j+1]==0) j++;
			if (i==1&&j==n) break;
			if (i==1){
				for(k=1;k<=m&&j-k+1>=i;k++)
					a[j-k+1]=1;
			} else 
			if (j==n){
				for(k=1;k<=m&&i+k-1<=j;k++)
					a[i+k-1]=1;
			} else {
				for(k=1;k<=m&&i+k-1<j-k+1;k++)
					a[i+k-1]=a[j-k+1]=1;
			}
			i=j+1;
		} 
		for(i=1;i<=n;i++) printf("%d",a[i]); printf("\n");
	}
}