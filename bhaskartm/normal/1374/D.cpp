#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define endl '\n'
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n ,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		map<int, int>m;
		for(int i=0; i<n; i++){
			if(arr[i]%k==0){
				continue;
			}
			m[(arr[i]%k)]++;
		}
		int maxi=0;
		for(auto it=m.begin(); it!=m.end(); it++){
			int rem=(it->first);
			int nums=(it->second);
			maxi=max(maxi, 1+(nums-1)*k+(k-rem));
		}
		cout<<maxi<<endl;
	}
	
	return 0;
}