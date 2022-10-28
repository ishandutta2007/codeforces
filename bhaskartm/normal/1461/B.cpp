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
	int t;
	cin>>t;
	
	while(t--){
		int n, m;
		cin>>n>>m;
		char arr[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		int l[n][m];
		int r[n][m];
		for(int i=0; i<m; i++){
			if(arr[0][i]=='*'){
				l[0][i]=1;
				r[0][i]=1;
			}
			else{
				l[0][i]=0;
				r[0][i]=0;
			}
		}
		for(int i=1; i<n; i++){
			for(int j=0; j<m; j++){
				if(j==0){
					if(arr[i][j]=='*'){
						l[i][j]=1;
					}
					else{
						l[i][j]=0;
					}
					continue;
				}
				if(arr[i][j]=='.'){
					l[i][j]=0;
					continue;
				}
				else{
					l[i][j]=1+min(l[i-1][j], l[i][j-1]);
				}
			}
			for(int j=m-1; j>=0; j--){
				if(j==m-1){
					if(arr[i][j]=='*'){
						r[i][j]=1;
					}
					else{
						r[i][j]=0;
					}
					continue;
				}
				if(arr[i][j]=='.'){
					r[i][j]=0;
					continue;
				}
				else{
					r[i][j]=1+min(r[i-1][j], r[i][j+1]);
				}
			}
		}
		int ans=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				ans+=min(r[i][j], l[i][j]);
				
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}