#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
int cnt[50010][30];
int pw(int x,int y){
	if(y==0)return 1;
	int ans=pw(x,y/2);
	ans=1ll*ans*ans%mod;
	if(y%2)ans=1ll*ans*x%mod;
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			cnt[j][x]++;
		}
	}
	int fac=1,out=0;
	for(int i=1;i<=n;i++){
		fac=1ll*fac*i%mod;
	}
	for(int i=1;i<=m;i++){
		int sum=0,ans=1;
		for(int j=n;j>=1;j--){
			sum+=cnt[i][j+1];
			ans=1ll*ans*sum%mod;
			sum--;
		}
		out=(out+1-1ll*pw(fac,mod-2)*ans%mod+mod)%mod;
	}
	cout<<out<<endl;
	return 0;
}