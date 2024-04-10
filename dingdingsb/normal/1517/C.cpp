#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int n,p[N];
int a[N][N];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		//i >= n-i+1
		int cnt=1;//n-i+cnt,cnt
		for(int j=1;j<=n;j++)
			if(p[j]>=n-i+1)
				a[n-i+cnt][cnt]=p[j],cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
}