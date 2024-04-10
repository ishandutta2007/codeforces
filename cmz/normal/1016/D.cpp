#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int n,m;
int a[maxn],b[maxn],sum1,sum2;
int Ans[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),sum1^=a[i];
	for (int i=1;i<=m;++i) scanf("%d",&b[i]),sum2^=b[i]; 
	if (sum1!=sum2) return puts("NO"),0;
	for (int i=1;i<=n;++i) Ans[i][1]=a[i];
	for (int i=1;i<=m;++i) Ans[n][i]=b[i];
	sum2^=b[1]; Ans[n][1]=a[n]^sum2;
	puts("YES");
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j) printf("%d ",Ans[i][j]);
		if (i!=n) puts("");
	}
	return 0;
}