#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'
const int N=1000000000;
int cnt[100005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	char arr[n][m];
	int dpl[n][m];
	int dpr[n][m];
	int up[n][m];
	int down[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
			dpl[i][j]=0;
			dpr[i][j]=0;
			up[i][j]=0;
			down[i][j]=0;
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i-1][j]!=arr[i][j]){
				up[i][j]=0;
			}
			else{
				up[i][j]=up[i-1][j]+1;
			}
		}
	}
	for(int i=n-2; i>=0; i--){
		for(int j=0; j<m; j++){
			if(arr[i][j]!=arr[i+1][j]){
				down[i][j]=0;
			}
			else{
				down[i][j]=1+down[i+1][j];
			}
		}
	}
	
	for(int c=m-2; c>=0; c--){
		for(int r=0; r<n; r++){
			if(arr[r][c]!=arr[r][c+1]){
				dpl[r][c]=0;
				continue;
			}
			dpl[r][c]=min(up[r][c], down[r][c]);
			dpl[r][c]=min(dpl[r][c], 1+dpl[r][c+1]);
		}
	}
	for(int c=1; c<m; c++){
		for(int r=0; r<n; r++){
			if(arr[r][c]!=arr[r][c-1]){
				dpr[r][c]=0;
				continue;
			}
			dpr[r][c]=min(up[r][c], down[r][c]);
			dpr[r][c]=min(dpr[r][c], 1+dpr[r][c-1]);
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int val=min(dpr[i][j], dpl[i][j]);
			ans+=(val+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}