#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int dp[75][75][75][75]; // row // ith elennt // rem //num elemnt 
int dp2[75][75]; //row //rem // 
int val[75][75];


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k;
	int arr[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		
		for(int j=0; j<m; j++){
			for(int l=0; l<k; l++){
				for(int tot=0; tot<=m; tot++){
					dp[i][j][l][tot]=-1e9;
				}
				
			}
		}
		
		dp[i][0][0][0]=0;
		dp[i][0][(arr[i][0]%k)][1]=arr[i][0];
		for(int j=0; j<m-1; j++){
			for(int l=0; l<k; l++){
				for(int l2=0; l2<m; l2++){
					dp[i][j+1][(l)][l2]=max(dp[i][j+1][(l)][l2], dp[i][j][(l)][l2]);
					dp[i][j+1][(l+arr[i][j+1])%k][l2+1]=max(dp[i][j+1][(l+arr[i][j+1])%k][l2+1], dp[i][j][(l)][l2]+arr[i][j+1]);
				}
			}
		}
		
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			val[i][j]=-1e9;
			for(int l=0; l<=(m/2); l++){
				val[i][j]=max(val[i][j], dp[i][m-1][j][l]);
			}
		}
	}
	for(int i=0; i<75; i++){
		for(int j=0; j<75; j++){
			dp2[i][j]=-1e9;
		}
	}
	for(int i=0; i<k; i++){
		dp2[0][i]=val[0][i];
	}
	for(int i=0; i<n-1; i++){
		for(int j=0; j<k; j++){
			for(int l=0; l<k; l++){
				dp2[i+1][(j+val[i+1][l])%k]=max(dp2[i+1][(j+val[i+1][l])%k], dp2[i][j]+val[i+1][l]);
			}
		}
	}
	cout<<dp2[n-1][0]<<endl;
	return 0;
}