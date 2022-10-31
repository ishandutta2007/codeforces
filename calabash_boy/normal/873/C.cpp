#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
int sum[maxn][maxn];
int m,n,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&sum[i][j]);
		}
	}
	for (int j=1;j<=m;j++){
		for (int i=1;i<=n;i++){
			sum[i][j]+=sum[i-1][j];
		}
	}
	int ans =0,cnt=0;
	for (int j=1;j<=m;j++){
		int temp = -1;
		int tempx =-1;
		for (int i=1;i<=n-k+1;i++){
			if (sum[i+k-1][j]-sum[i-1][j]>temp){
				temp = sum[i+k-1][j]-sum[i-1][j];
				tempx = i;
			}
		}
		ans+=sum[tempx-1][j];
		cnt+=temp;
	}
	cout<<cnt<<" "<<ans<<endl;
}