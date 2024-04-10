#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[270000][100];
ll n;int m,cnt=0;
int num[19],zt[10];
void getv(ll x){
	num[cnt]=x%10;
	cnt++;
	zt[x%10]++;
	if (x>9) getv(x/10);
}
ll dd[20];
int main(){
	dd[0]=1;
	for (int i=1;i<20;i++) dd[i]=dd[i-1]*i;
	cin>>n>>m;getv(n);
	dp[0][0]=1;
	for (int i=1;i<(1<<cnt);i++){
		int ns=__builtin_popcount(i);
		for (int j=0;j<cnt;j++)if((1<<j)&i)if(ns!=1 || num[j]!=0)
			for (int k=0;k<m;k++)
				dp[i][(k*10+num[j])%m]+=dp[i^(1<<j)][k];
	}
	for (int i=0;i<10;i++) dp[(1<<cnt)-1][0]/=dd[zt[i]];
	cout<<dp[(1<<cnt)-1][0];
}