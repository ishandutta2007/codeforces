#include<bits/stdc++.h>
using namespace std;
const int M=1e6+3;
char c[2003];
int n,cnt,v[2003];
int dp[4003][2003];
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if(c[i]=='+'||c[i]=='-'){
			++cnt;
			if(c[i-1]<'0'||c[i-1]>'9')v[cnt]=1;
		}
		if(c[i]=='*'||c[i]=='/'){
			++cnt;
			if(c[i-1]<'0'||c[i-1]>'9'){
				puts("0");
				return 0;
			}
		}
	}
	if(c[n]<'0'||c[n]>'9'){
		puts("0");return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<=2*cnt;i++)for(int j=0;j<=min(i,cnt);j++)if(dp[i][j]){
		int k=i-j;
		if(j<k)continue;
		if(j<cnt)add(dp[i+1][j+1],dp[i][j]);
		if(v[k+1]&&i<2*cnt-1&&j<cnt)add(dp[i+2][j+1],dp[i][j]);
		if(!v[k+1])add(dp[i+1][j],dp[i][j]);
	}
	printf("%d",dp[2*cnt][cnt]);
}