#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
const int maxn = 2e5+100;
int fac[maxn];
int n,k;
int power(int x,int y){
	int ans=1;
	while (y){
		if (y&1){
			ans = 1LL*ans*x%MOD;
		}
		x = 1LL*x*x%MOD;
		y>>=1;
	}
	return ans;
}
int C(int x,int y){
	return 1LL*fac[x]*power(fac[y],MOD-2)%MOD*power(fac[x-y],MOD-2)%MOD;
}
int S(int x,int y){
	LL res = 0;
	for (int i=0,flag=1;i<=y;i++,flag=-flag){
		res+=1LL*flag*C(y,i)*power(y-i,x)%MOD;
		res=(res+MOD)%MOD;
	}	
	return res*power(fac[y],MOD-2)%MOD;
}
void init(){
	fac[0]=1;
	for (int i=1;i<maxn;i++){
		fac[i] = 1LL*fac[i-1]*i%MOD;
	}
}
int main(){
	init();
	cin>>n>>k;
	int sum =0;
	for (int i=0;i<n;i++){
		int ai;
		scanf("%d",&ai);
		sum+=ai;
		if (sum>=MOD){
			sum-=MOD;
		}
	}
	cout<<1LL*sum*((S(n,k)+1LL*(n-1)*S(n-1,k)%MOD)%MOD)%MOD<<endl;
	return 0;
}