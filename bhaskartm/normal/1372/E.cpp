#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=105;
int n, m;
int le[N][N];
int ri[N][N];
int dp[N][N];
bool che[N][N];

int f(int l, int r){
	if(l>r){
		return 0;
	}
	if(che[l][r]){
		return dp[l][r];
	}
	che[l][r]=1;
	int ans=0;
	for(int i=l; i<=r; i++){
		int val=0;
		for(int j=1; j<=n; j++){
			if(le[j][i]>=l && ri[j][i]<=r){
				val++;
			}
		}
		ans=max(ans, val*val+f(l, i-1)+f(i+1, r));
	}
	dp[l][r]=ans;
	return ans;
}
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		while(k--){
			int l, r;
			cin>>l>>r;
			for(int j=l; j<=r; j++){
				le[i][j]=l;
				ri[i][j]=r;
			}
		}
	}
	cout<<f(1, m)<<endl;
	return 0;
}