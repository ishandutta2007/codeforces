#include<bits/stdc++.h>

using namespace std;

const int maxn=505;

int n,m,f;
int ok[maxn][maxn];
int dp[maxn];
int cst[maxn][maxn];

int main(){
	cin>>n>>m>>f;
	for(int i=1;i<=n;i++){
		char _[maxn];
		cin>>(_+1);
		for(int j=1;j<=m;j++)ok[i][j]=(_[j]=='1'); 
	}
	memset(cst,0x3f,sizeof(cst));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)ok[i][j]+=ok[i][j-1];
		for(int j=1;j<=m;j++){
			for(int k=j;k<=m;k++){
				int h=ok[i][m]-ok[i][k]+ok[i][j-1];
				cst[i][h]=min(k-j+1,cst[i][h]);
			}
		}
		for(int j=ok[i][m];j<=m;j++)cst[i][j]=0;
		/*for(int j=0;j<=m;j++){
			cout<<cst[i][j]<<' ';
		}
		cout<<endl;*/
	}
	memset(dp,0xc0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=f;j>=1;j--){ 
			for(int k=0;k<=m;k++){
				if(j-k>=0)dp[j]=max(dp[j],dp[j-k]+cst[i][0]-cst[i][k]);
			}
		}
	} 
	long long ans=0x3fff3fff3fff3fff,sm=0;
	for(int i=1;i<=n;i++)sm+=cst[i][0];
	for(int i=0;i<=f;i++){
		ans=min(ans,sm-dp[i]); 
	} 
	cout<<ans;
	return 0; 
}