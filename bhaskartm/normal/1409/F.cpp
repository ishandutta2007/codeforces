#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
int dp[205][205][205];
int dpc[205][205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	string s, t;
	cin>>s>>t;
	for(int i=0; i<=200; i++){
		for(int j=0; j<=200; j++){
			for(int k=0; k<=200; k++){
				dp[i][j][k]=-1e9;
				dpc[i][j][k]=-1e9;
			}
		}
	}
	if(t[0]==t[1]){
		int cnt=0;
		for(int i=0; i<n; i++){
			if(s[i]==t[0]){
				cnt++;
			}
		}
		int rem=n-cnt;
		int val=min(rem, k);
		cnt+=val;
		cout<<((cnt)*(cnt-1))/2;
		return 0;
	}
	if(s[0]==t[0]){
		dp[1][0][0]=0;
	}
	else{
		dp[1][0][1]=0;
	}
	if(s[0]==t[1]){
		dp[0][1][0]=0;
	}
	else{
		dp[0][1][1]=0;
	}
	if(s[0]!=t[0] && s[0]!=t[1]){
		dp[1][0][1]=0;
		dp[0][1][1]=0;
		dp[0][0][0]=0;
	}
	for(int i=1; i<s.size(); i++){
		for(int j0=0; j0<=(i+1); j0++){
			for(int j1=0; j1<=i+1-j0; j1++){
				for(int k0=0; k0<=min((i+1), k); k0++){
					
					if(s[i]==t[0]){
						dpc[j0+1][j1][k0]=max(dp[j0][j1][k0], dpc[j0+1][j1][k0]);
						dpc[j0][j1+1][k0+1]=max(dpc[j0][j1+1][k0+1], dp[j0][j1][k0]+j0);
						
					}
					else if(s[i]==t[1]){
						dpc[j0+1][j1][k0+1]=max(dpc[j0+1][j1][k0+1], dp[j0][j1][k0]);
						dpc[j0][j1+1][k0]=max(dpc[j0][j1+1][k0], j0+dp[j0][j1][k0]);
						
					}
					else{
						dpc[j0][j1][k0]=max(dpc[j0][j1][k0], dp[j0][j1][k0]);
						dpc[j0+1][j1][k0+1]=max(dpc[j0+1][j1][k0+1], dp[j0][j1][k0]);
						dpc[j0][j1+1][k0+1]=max(dpc[j0][j1+1][k0+1], dp[j0][j1][k0]+j0);
					}
				}
			}
		}
		for(int j0=0; j0<=(i+1); j0++){
			for(int j1=0; j1<=(i+1)-j0; j1++){
				for(int k0=0; k0<=k+1; k0++){
					dp[j0][j1][k0]=max(dp[j0][j1][k0], dpc[j0][j1][k0]);
				}
			}
		}
		
	}
	int maxi=0;
	for(int i=0; i<=s.size(); i++){
		for(int j=0; j<=s.size(); j++){
			for(int k1=0; k1<=k; k1++){
				maxi=max(dp[i][j][k1], maxi);
				
			}
		}
	}
	cout<<max(maxi, 0);
	return 0;
}