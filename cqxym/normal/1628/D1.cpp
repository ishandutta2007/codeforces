#include<iostream>
using namespace std;
#define R register int
#define P 1000000007
int f[2001][2001];
inline void Solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(R i=1;i<=n;i++){
		for(R j=1;j!=i&&j<=m;j++){
			f[i][j]=f[i-1][j]+f[i-1][j-1];
			if(f[i][j]>=P){
				f[i][j]-=P;
			}
			if((f[i][j]&1)==1){
				f[i][j]+=P;
			}
			f[i][j]>>=1;
		}
		if(i<=m){
			f[i][i]=f[i-1][i-1]+k;
			if(f[i][i]>=P){
				f[i][i]-=P;
			}
		}
	}
	cout<<f[n][m]<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}