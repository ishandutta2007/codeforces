#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m,L,R,A,B,num[33][2];
ll DP[2][2];
int main(){
	cin>>n>>m>>L>>R;
	if (n<m) swap(n,m); 
	A=(R+1)/2-L/2,B=R/2-(L-1)/2;A%=MOD,B%=MOD;
	num[0][0]=B,num[0][1]=A;
	for (int i=1;i<33;i++){
		num[i][0]=(num[i-1][1]*num[i-1][1]%MOD+num[i-1][0]*num[i-1][0]%MOD)%MOD;
		num[i][1]=(num[i-1][1]*num[i-1][0]%MOD+num[i-1][0]*num[i-1][1]%MOD)%MOD;
	}
	int now=0,vis=0;
	for (int i=0;i<33;i++)if ((1ll<<i)&n){
		if (vis==0){
			for (int j=0;j<2;j++) DP[now][j]=num[i][j];
			vis=1;
		}else{
			now^=1;
			DP[now][0]=(DP[now^1][1]*num[i][1]%MOD+DP[now^1][0]*num[i][0]%MOD)%MOD;
			DP[now][1]=(DP[now^1][0]*num[i][1]%MOD+DP[now^1][1]*num[i][0]%MOD)%MOD;
		}
	}
	A=DP[now][1],B=DP[now][0];
	num[0][0]=B,num[0][1]=A;
	for (int i=1;i<33;i++){
		num[i][0]=(num[i-1][1]*num[i-1][1]%MOD+num[i-1][0]*num[i-1][0]%MOD)%MOD;
		num[i][1]=(num[i-1][1]*num[i-1][0]%MOD+num[i-1][0]*num[i-1][1]%MOD)%MOD;
	}
	now=0,vis=0;
	for (int i=0;i<33;i++)if ((1ll<<i)&m){
		if (vis==0){
			for (int j=0;j<2;j++) DP[now][j]=num[i][j];
			vis=1;
		}else{
			now^=1;
			DP[now][0]=(DP[now^1][1]*num[i][1]%MOD+DP[now^1][0]*num[i][0]%MOD)%MOD;
			DP[now][1]=(DP[now^1][0]*num[i][1]%MOD+DP[now^1][1]*num[i][0]%MOD)%MOD;
		}
	}
	if (n*m%2)cout<<(DP[now][0]+DP[now][1])%MOD;
	else cout<<DP[now][0];
}