#include<bits/stdc++.h>
using namespace std;
#define int long long
#define DIG 19
int dp[DIG+1][10][DIG+1];
void dp_prework(){
	dp[0][0][0]=1;
	for(int i=1;i<=DIG;i++)for(int j=0;j<=9;j++)for(int k=0;k<=i;k++)for(int o=0;o<=9;o++)
		if(!j||k)dp[i][j][k]+=dp[i-1][o][k-!!j];
//	for(int i=1;i<=DIG;i++)for(int j=0;j<=9;j++)for(int k=0;k<=i;k++)
//		printf("dp[%lld][%lld][%lld]=%lld\n",i,j,k,dp[i][j][k]);
}
int ans(int r){
	if(!r)return 0;
//	cout<<"r="<<r<<"\n";
	int res=0,dig[DIG+1],cnt=0,no=0,i,j,k;
	while(r)dig[++cnt]=r%10,r/=10;
	for(i=1;i<cnt;i++)for(j=1;j<=9;j++)for(k=1;k<=3;k++)res+=dp[i][j][k];
//	cout<<""<<res<<"\n";
	for(i=0;i<cnt;i++){
		if(i)no+=!!dig[cnt-i+1];
		for(j=!i;j<dig[cnt-i];j++)for(k=0;k<=3-no;k++)res+=dp[cnt-i][j][k];
//		cout<<""<<i<<""<<res<<"\n";
	}
	no+=!!dig[1];
	res+=no<=3;
//	cout<<""<<r<<""<<res<<"\n";
	return res;
}
signed main(){
	dp_prework();
	ans(1001);ans(1000);
	int qu;scanf("%lld",&qu);
	while(qu--){
		int a,b;scanf("%lld%lld",&a,&b);
		printf("%lld\n",ans(b)-ans(a-1));
	}
	return 0;
}
/*1
4
1 1000
1024 1024
65536 65536
999999 1000001
*/