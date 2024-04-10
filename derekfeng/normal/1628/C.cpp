#include<bits/stdc++.h>
using namespace std;
int n,a[1005][1005],ans[1005][1005],sum;
void ask(){
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)ans[i][j]=0;
	for(int i=2;i<=n;i++){
		ans[i][i-1]=a[i-1][i-1]^ans[i-1][i-2];
		for(int j=i+1,k=i-2;j<=n&&k>0;j++,k--){
			ans[j][k]=a[j-1][k]^a[k][j-1]^ans[j-1][k+1]^ans[j-1][k-1]^ans[j-2][k];
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)sum^=ans[i][j];
}
void sol(){
	scanf("%d",&n),sum=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	ask();
	for(int i=1;i<=n;i++)reverse(a[i]+1,a[i]+n+1);
	ask();
	printf("%d\n",sum);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}