#include <bits/stdc++.h>
using namespace std;
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
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<int>ans;
		int don[n];
		
		while(1){
			bool che=1;
			for(int i=0; i<n-1; i++){
				if(arr[i]>arr[i+1]){
					che=0;
					break;
				}
			}
			if(che){
				break;
			}
			bool is[n+1];
			for(int i=0; i<=n; i++){
				is[i]=0;
			}
			for(int i=0; i<n; i++){
				is[arr[i]]=1;
			}
			int mex=-1;
			for(int i=0; i<=n; i++){
				if(is[i]==0){
					mex=i;
					break;
				}
			}
			
			if(mex==n){
				for(int i=0; i<n; i++){
					if(arr[i]!=i){
						ans.pb(i);
						arr[i]=mex;
						break;
					}
				}
				continue;
			}
			arr[mex]=mex;
			ans.pb(mex);
		}
		cout<<ans.size()<<endl;
		for(auto u:ans){
			cout<<u+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}