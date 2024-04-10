#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int myp(int x,int t){
	int ans=1,res=x;
	for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
	return ans;
}
int f[505][505],n,K,ans,C[505][505];
int pw[505][505];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=0;i<505;i++)for(int j=0;j<505;j++)pw[i][j]=myp(i,j);
	for(int i=0;i<505;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	for(int i=2;i<=n;i++)for(int j=1;j<=K;j++){
		int sub=i-1;
		if(j<=sub)for(int k=1;k<=i;k++)(f[i][j]+=(ll)C[i][k]*pw[j-1][i-k]%M)%=M;
		else for(int k=1;k<=i;k++)(f[i][j]+=(ll)f[k][j-sub]*pw[sub][i-k]%M*C[i][k]%M)%=M;
		if(i==n)(ans+=f[i][j])%=M;
	}
	printf("%d",ans);
}