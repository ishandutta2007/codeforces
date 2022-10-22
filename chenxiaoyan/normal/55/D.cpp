#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x/gcd(x,y)*y;}
const int DIG=10,LEN=19;
int pw[LEN+1],lcma[2521][2521];
int dp[LEN+1][2520][48];
int id[2521];const int mng[]={1,2,3,4,5,6,7,8,9,10,12,14,15,18,20,21,24,28,30,35,36,40,42,45,56,60,63,70,72,84,90,105,120,126,140,168,180,210,252,280,315,360,420,504,630,840,1260,2520};
void dp_init(){
	for(int i=0;i<48;i++)id[mng[i]]=i;
	pw[0]=1;
	for(int i=1;i<=19;i++)pw[i]=pw[i-1]*10%2520;
	for(int i=0;i<48;i++)lcma[mng[i]][0]=lcma[0][mng[i]]=mng[i];
	for(int i=0;i<48;i++)for(int j=0;j<48;j++)lcma[mng[i]][mng[j]]=lcm(mng[i],mng[j]);
	dp[0][0][0]=1;
	for(int i=0;i<19;i++)for(int j=0;j<2520;j++)for(int k=0;k<48;k++)
		for(int o=0;o<=9;o++)
			dp[i+1][(j+o*pw[i])%2520][id[lcma[mng[k]][o]]]+=dp[i][j][k];
}
int qu;
bool ok(int cnt,int dig[],int num){
	for(int i=0;i<cnt;i++)if(dig[i]&&num%dig[i])return false;
	return true;
}
int ans(int r){
	if(!r)return 0;
	int cpy=r,cnt=0,dig[19];
	while(r)dig[cnt++]=r%10,r/=10;
	int res=0;
	for(int i=1;i<cnt;i++)
		for(int j=0;j<48;j++)for(int k=1;k<=9;k++){
			int _lcm=lcma[k][mng[j]];
			for(int o=0;o<2520;o+=_lcm)res+=dp[i-1][(o-k*pw[i-1]%2520+2520)%2520][j];
		}
	int now=0,nowlcm=1;
	for(int i=0;i<cnt;i++){
		if(i)(now+=pw[cnt-i]*dig[cnt-i])%=2520,nowlcm=lcma[nowlcm][dig[cnt-i]];
		for(int j=0;j<48;j++)for(int k=!i;k<dig[cnt-i-1];k++){
			int _lcm=lcma[lcma[nowlcm][k]][mng[j]];
			for(int o=0;o<2520;o+=_lcm)res+=dp[cnt-i-1][(o-now-k*pw[cnt-i-1]%2520+5040)%2520][j];
		}
	}
	return res+ok(cnt,dig,cpy);
}
signed main(){
	dp_init();
	scanf("%lld",&qu);
	while(qu--){
		int l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",ans(r)-ans(l-1));
	}
	return 0;
}
/*1
1
1 9
*/
/*2
1
12 15
*/
/*3
10
1 1000
1 1000
1 1000
1 1000
1 1000
1 1000
1 1000
1 1000
1 1000
1 1000
*/