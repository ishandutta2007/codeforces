#include<bits/stdc++.h>
using namespace std;
int n,M,f[404][404];
int C[1003][1003],pw[404];
int main(){
	cin>>n>>M;
	C[0][0]=1;
	for(int i=1;i<=1000;C[i][0]=1,i++)
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	pw[0]=1;
	for(int i=1;i<404;i++)pw[i]=pw[i-1]*2%M;
	for(int i=1;i<=n;i++){
		f[i][1]=pw[i-1];
		for(int j=1;j<i-1;j++){
			int Ld=i-j-1;
			for(int k=1;k*2-1<=j;k++)(f[i][k+1]+=(long long)f[j][k]*pw[Ld-1]%M*C[i-k][Ld]%M)%=M;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)(ans+=f[n][i])%=M;
	cout<<ans;
}