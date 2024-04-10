#include<bits/stdc++.h>
using namespace std;
int a[1000001],dp[2][3][3];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	while(n--){int x;scanf("%d",&x);a[x]++;}
//	for(i=1;i<=m;i++)cout<<a[i]<<" ";puts("");
    if(m==1)return !printf("%d",a[1]/3);
    if(m==2)return !printf("%d",a[1]/3+a[2]/3);
	dp[1][0][0]=a[1]/3+a[2]/3+a[3]/3;
	if(a[1]&&a[2]&&a[3])dp[1][1][0]=1+(a[1]-1)/3+(a[2]-1)/3+(a[3]-1)/3;
	if(a[1]>1&&a[2]>1&&a[3]>1)dp[1][2][0]=2+(a[1]-2)/3+(a[2]-2)/3+(a[3]-2)/3;
	for(int i=4;i<=m;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int o=0;o<3;o++)
		if(a[i-4]>=o&&a[i-3]>=k+o&&a[i-2]>=j+k+o&&a[i-1]>=j+k&&a[i]>=j){
			int dec=(a[i-1]-k)/3-(a[i-1]-j-k)/3+(a[i-2]-k-o)/3-(a[i-2]-j-k-o)/3;
			dp[i&1][j][k]=max(dp[i&1][j][k],dp[!(i&1)][k][o]+j+(a[i]-j)/3-dec);
		}
	printf("%d",*max_element(&dp[m&1][0][0],&dp[m&1][2][2]+1));
	return 0;
}
/*1
10 6
2 3 3 3 4 4 4 5 5 6
*/
/*2
12 6
1 5 3 3 3 4 3 5 3 2 3 3
*/
/*3
13 5
1 1 5 1 2 3 3 2 4 2 3 4 5
*/