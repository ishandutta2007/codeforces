#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, g, b;
	cin>>r>>g>>b;
	int dp[r+1][g+1][b+1];
	for(int i=0; i<=r; i++){
		for(int j=0; j<=g; j++){
			for(int k=0; k<=b; k++){
				dp[i][j][k]=0;
			}
		}
	}
	vector<int>rr;
	vector<int>gg;
	vector<int>bb;
	for(int i=0; i<r; i++){
		int x;
		cin>>x;
		rr.pb(x);
	}
	for(int i=0; i<g; i++){
		int x;
		cin>>x;
		gg.pb(x);
	}
	for(int i=0; i<b; i++){
		int x;
		cin>>x;
		bb.pb(x);
	}
	sort(rr.begin(), rr.end());
	sort(gg.begin(), gg.end());
	sort(bb.begin(), bb.end());
	reverse(rr.begin(), rr.end());
	reverse(gg.begin(), gg.end());
	reverse(bb.begin(), bb.end());
	dp[1][1][0]=rr[0]*gg[0];
	dp[1][0][1]=rr[0]*bb[0];
	dp[0][1][1]=gg[0]*bb[0];
	for(int i=0; i<=r; i++){
		for(int j=0; j<=g; j++){
			for(int k=0; k<=b; k++){
				if(i==0 && j==0 && k==0){
					continue;
				}
				if((i+j+k)%2==1){
					continue;
				}
				if(i>j+k || j>i+k || k>i+j){
					continue;
				}
				if(i>0 && j>0){
					dp[i][j][k]=max(dp[i][j][k], dp[i-1][j-1][k]+rr[i-1]*gg[j-1]);
				}
				if(i>0 && k>0){
					dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]+rr[i-1]*bb[k-1]);
				}
				if(j>0 && k>0){
					dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]+gg[j-1]*bb[k-1]);
				}
			}
		}
	}
	int maxi=0;
	for(int i=0; i<=r; i++){
		for(int j=0; j<=g; j++){
			for(int k=0; k<=b; k++){
				maxi=max(maxi, dp[i][j][k]);
			}
		}
	}
	cout<<maxi;
	return 0;
}