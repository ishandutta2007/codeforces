#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M,n;
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int f[53][2503],g[53][53][2503];
int coef[53],fc[53];
int C[53][53];
int sum[2503];
int ans;
int main(){
	cin>>n>>M;
	C[0][0]=1;
	for(int i=1;i<=n;C[i][0]=1,i++)for(int j=1;j<=n;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	fc[0]=1;
	for(int i=1;i<=n;i++)fc[i]=(ll)fc[i-1]*i%M;
	f[1][0]=1;
	for(int i=2;i<=n;i++)for(int j=0;j<=n*n;j++)if(f[i-1][j])
		for(int k=0;k<i;k++)add(f[i][j+i-1-k],f[i-1][j]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=0;k<=n*n;k++)if(f[j-1][k])
				add(g[i][j][k+i-1],f[j-1][k]);
	for(int i=1;i<=n;i++){
		memset(sum,0,sizeof(sum));
		for(int j=1;j<=n;j++){
			for(int k=0;k<=n*n;k++)add(coef[i],(ll)sum[k+1]*g[j][i][k]%M);
			int S=0;
			for(int k=n*n;~k;k--){
				add(S,g[j][i][k]);
				add(sum[k],S);
			}
		}
	}
	for(int i=0;i<n;i++){
		add(ans,(ll)coef[n-i]*C[n][i]%M*fc[i]%M);
	}
	cout<<ans;
}