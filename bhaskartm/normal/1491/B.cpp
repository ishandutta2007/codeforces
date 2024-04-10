#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;
int arr[N];

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, u, v;
		cin>>n>>v>>u;
		int arr[n];
		int ans=1e18;
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		for(int i=0; i<n-1; i++){
			int val=abs(arr[i+1]-arr[i]);
			if(val>=2){
				ans=0;
			}
			else if(val==1){
				ans=min(ans, min(u, v));
			}
			else if(val==0){
				ans=min(ans, min(u+v, 2*u));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}