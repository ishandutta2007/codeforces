#include <bits/stdc++.h>
using namespace std;
void read(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const int MOD=1e9+7; 
int dp[1000004][3];
string c;
int main(){
	read(c);
	int n=c.size();c="$"+c;
	if (c[1]=='1')
		dp[1][1]=1;
	if (c[1]=='*')
		dp[1][2]=1;
	if (c[1]=='0')
		dp[1][0]=1;
	if (c[1]=='?')
		dp[1][2]=dp[1][1]=dp[1][0]=1;
	for (int i=2;i<=n;i++){
		if (c[i]=='0')dp[i][0]=dp[i-1][0];
		if (c[i]=='*')dp[i][2]=(dp[i-1][2]+dp[i-1][1])%MOD;
		if (c[i]=='1')dp[i][0]=dp[i-1][2],dp[i][1]=dp[i-1][0];
		if (c[i]=='2')dp[i][1]=dp[i-1][2];
		if (c[i]=='?'){
			dp[i][2]=(dp[i-1][2]+dp[i-1][1])%MOD;
			dp[i][0]=(dp[i-1][2]+dp[i-1][0])%MOD;
			dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
		}
	}
	write((dp[n][0]+dp[n][2])%MOD);
}