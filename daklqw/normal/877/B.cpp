#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<ctime>
#include<vector>

#define For(a,b,c) for (int a=b;a<c;i++)
#define ForD(a,b,c) for (int a=b;a>c;a--)
#define LL long long
#define _N putchar('\n');
#define _K putchar(' ');

const int inf=0x7fffffff;
const int maxn=300100;
const int maxm=300100;
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int abs(int a){return a>0?a:-a;}

/*=================================================================================*/

int n,m,ls,a,b;
int dp[6000][3];
char s[6000]; 
char last;
int main(){
	scanf("%s",s);
	ls=strlen(s);
	if (s[0]=='a'){
		dp[0][2]=dp[0][1]=dp[0][0]=1;
	}else dp[0][2]=dp[0][0]=0,dp[0][1]=1;
	for (int i=1;i<ls;i++){
		if (s[i]=='a'){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1];
			dp[i][2]=max(dp[i-1][1],dp[i-1][2])+1;
		}else{
			dp[i][0]=dp[i-1][0];
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
			dp[i][2]=dp[i-1][2];
		}
	}
	printf("%d\n",max(dp[ls-1][2],max(dp[ls-1][0],dp[ls-1][1])));
	return 0;
}