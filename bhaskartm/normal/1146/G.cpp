#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int  N=55;

int n, h, m;

int dp[N][N][N]; //l, r, max height atmost
bool che[N][N][N];
int cost[N][N][N][N]; //l, r, mid, value at mid 

int f(int l, int r, int maxi){
	if(l>r){
		return 0;
	}
	if(che[l][r][maxi]){
		return dp[l][r][maxi];
	}
	che[l][r][maxi]=1;
	for(int mid=l; mid<=r; mid++){
		for(int val=0; val<=maxi; val++){
			dp[l][r][maxi]=max(dp[l][r][maxi], val*val+cost[l][r][mid][val]+f(l, mid-1, val)+f(mid+1, r, val));
		}
	}
	return dp[l][r][maxi];
}
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>h>>m;
	for(int i=0; i<m; i++){
		int l, r, x, c;
		cin>>l>>r>>x>>c;
		for(int ll=1; ll<=l; ll++){
			for(int rr=r; rr<=n; rr++){
				for(int mid=l; mid<=r; mid++){
					for(int co=x+1; co<=h; co++){
						cost[ll][rr][mid][co]-=c;
					}
				}
			}
		}
	}
	cout<<f(1, n, h)<<endl;
	return 0;
}