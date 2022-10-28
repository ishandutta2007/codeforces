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
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int cnt[31];
		for(int i=0; i<=30; i++){
			cnt[i]=0;
		}
		for(int i=0; i<n; i++){
			for(int j=30; j>=0; j--){
				if((arr[i]>>j)==1){
					cnt[j]++;
					break;
				}
			}
		}
		int ans=0;
		for(int i=0; i<=30; i++){
			ans=ans+((cnt[i]*(cnt[i]-1))/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}