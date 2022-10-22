#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400+5;
int n,m,mod;
int dp0[N][N][2],dp1[N][N][2];
inline void add(int &x,int y){
	x=((x+y>=mod)?(x+y-mod):(x+y));
}
int main(){
	int i,j,k;
	cin>>n>>mod;
	dp0[2][1][0]=dp0[2][2][1]=dp0[1][0][0]=1;
	for(i=2;i<n;i++){
		memset(dp1,0,sizeof(dp1));
		for(j=1;j<=i;j++){
			add(dp1[j+1][j+1][0],dp0[j][0][0]);
			add(dp1[j+1][0][0],mod-dp0[j][0][0]);
		}
		for(j=1;j<=i;j++){
			for(k=1;k<=j;k++){
				add(dp1[j+1][k][0],dp0[j][k][0]);
				add(dp1[j+1][0][0],mod-dp0[j][k][0]);
				add(dp1[j+1][j+1][1],dp0[j][k][0]);
				add(dp1[j+1][k][1],mod-dp0[j][k][0]);
				add(dp1[j+1][j+1][1],dp0[j][k][1]);
				add(dp1[j+1][k][1],mod-dp0[j][k][1]);
				add(dp1[j][0][0],dp0[j][k][0]);
				add(dp1[j][0][0],dp0[j][k][1]);
			}
		}
		for(j=i+1;j;j--){
			for(k=j;k>=0;k--){
				add(dp1[j][k][0],dp1[j][k+1][0]);
				add(dp1[j][k][1],dp1[j][k+1][1]);
			}
		}
		memcpy(dp0,dp1,sizeof(dp1));
	}
	int ans=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++){
			add(ans,dp0[i][j][0]);
			add(ans,dp0[i][j][1]);
		}
	cout<<ans;
	return 0;
}