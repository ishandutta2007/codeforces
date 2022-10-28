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
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int las=0;
		int ans=0;
		for(int i=0; i<n; i++){
			int val=0;
			for(int j=0; j<=i-2; j++){
				if(arr[j]>=(i-j)){
					val++;
				}
			}
			int tot=val+las;
			int rem=arr[i]-1;
			if(tot>rem){
				las=tot-rem;
			}
			else{
				ans+=(rem-tot);
				las=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}