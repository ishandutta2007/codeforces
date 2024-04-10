#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int arr[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		int dt1[n+m];
		int dt0[n+m];
		int db1[n+m];
		int db0[n+m];
		for(int i=0; i<n+m; i++){
			dt1[i]=0;
			dt0[i]=0;
			db0[i]=0;
			db1[i]=0;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j]==1){
					dt1[i+j]++;
					db1[n+m-2-i-j]++;
				}
				else{
					dt0[i+j]++;
					db0[n+m-2-i-j]++;
				}
			}
		}
		int ans=0;
		if((n+m)%2==0){
		for(int i=0; i<(n+m-2)/2; i++){
			int one=dt1[i];
			one+=db1[i];
			int zero=db0[i];
			zero+=dt0[i];
			ans+=min(zero, one);
		}
		cout<<ans<<endl;
		}
		else{
			for(int i=0; i<=(n+m-2)/2; i++){
			int one=dt1[i];
			one+=db1[i];
			int zero=db0[i];
			zero+=dt0[i];
			ans+=min(zero, one);
		}
		cout<<ans<<endl;
		}
	}
	return 0;
}