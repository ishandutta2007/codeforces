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
		int n;
		cin>>n;
		int a[n][3];
		for(int i=0; i<3; i++){
			for(int j=0; j<n; j++){
				cin>>a[j][i];
			}
		}
		int ans[n];
		ans[0]=a[0][0];
		for(int i=1; i<n; i++){
			if(i==n-1){
				for(int j=0; j<3; j++){
					if(a[i][j]!=ans[i-1] && a[i][j]!=ans[0]){
						ans[i]=a[i][j];
					
					}
				}
				continue;
			}
			for(int j=0; j<3; j++){
				if(a[i][j]!=ans[i-1]){
					ans[i]=a[i][j];
					break;
				}
			}
			
		}
		
		for(int i=0; i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}