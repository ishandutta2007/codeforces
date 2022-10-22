#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	int res=1; 
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar();
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,sx,sy;
int dp[17000000],x[25],y[25];
map<int,int>mp;
int fr[17000004];
int mysqr(int x){
	return x*x;
}
int go(int a,int b){
	return mysqr(x[a]-x[b])+mysqr(y[a]-y[b]);
}
void output(int masks){
	if (masks==0){
		putchar('0'),putchar(' ');
		return;
	}
	int nmasks=masks-(masks&-masks);
	if (fr[masks]!=-1)nmasks^=(1<<fr[masks]);
	output(nmasks);
	write(mp[masks&-masks]+1),putchar(' ');
	if (fr[masks]!=-1)write(fr[masks]+1),putchar(' ');
	putchar('0'),putchar(' ');
}
int main(){
	for (int i=0;i<24;i++) mp[1<<i]=i;
	read(sx),read(sy),read(n);
	x[n]=sx,y[n]=sy;
	for (int i=0;i<n;i++) read(x[i]),read(y[i]);
	for (int i=0;i<(1<<n);i++) dp[i]=1e9;
	dp[0]=0;
	memset (fr,-1,sizeof(fr));
	for (int i=1;i<(1<<n);i++){
		int num=mp[i&-i];
		dp[i]=min(dp[i],dp[i^(1<<num)]+2*go(num,n));
		for (int j=0;j<n;j++) if (num!=j && (1<<j)&i && dp[i^(1<<num)^(1<<j)]+go(num,j)+go(j,n)+go(num,n)<dp[i]){
			fr[i]=j;
			dp[i]=dp[i^(1<<num)^(1<<j)]+go(num,j)+go(j,n)+go(num,n);
		}
	}
	write(dp[(1<<n)-1]),puts(""),output((1<<n)-1);
}