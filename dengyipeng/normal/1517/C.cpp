#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 505
using namespace std;

int n,i,j,k,p[maxn],a[maxn][maxn],res[maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++){
		a[i][i]=p[i],res[p[i]]=p[i]-1;
		for(j=i-1;j>=1;j--){
			if (res[a[i][j+1]]&&(!res[a[i-1][j]]||a[i-1][j-1]==a[i-1][j]))
				a[i][j]=a[i][j+1],res[a[i][j]]--;
			else
			if (res[a[i-1][j]]){
				a[i][j]=a[i-1][j],res[a[i][j]]--;
				for(k=j+1;!a[i][k]&&k<=i;k++)
					res[a[i][j]]--,a[i][k]=a[i][j];
			}
		}
	}
	for(i=1;i<=n;i++,printf("\n")) for(j=1;j<=i;j++) printf("%d ",a[i][j]);
}