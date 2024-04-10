#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
const int maxk = 5005;
int n,k;
LL s[maxk][maxk];
LL power(LL x,LL y){
	LL ans =1;
	while (y){
		if (y&1){
			ans = ans*x%MOD;
		}
		x = x * x % MOD; 
		y>>=1;
	}
	return ans;
}
int A(int x,int y){
	LL ans =1;
	for (int i=x-y+1;i<=x;i++){
		ans = ans*i%MOD;
	}
	return ans;
}
void init(){
	s[1][1]=1;
	for (int i=2;i<maxk;i++){
		for (int j=1;j<=i;j++){
			s[i][j] = s[i-1][j-1]+j*s[i-1][j]%MOD;
			s[i][j]%=MOD;
		}
	}
}
int main(){
	cin>>n>>k;
	init();
	LL ans =0;
	for (int j=1;j<=k;j++){
		if (j>n)break;
		ans = (ans+s[k][j]*A(n,j)%MOD*power(2,n-j)%MOD+MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}