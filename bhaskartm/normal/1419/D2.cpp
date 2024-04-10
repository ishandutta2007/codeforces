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
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	int ans[n];
	sort(arr, arr+n);
	int pt=0;
	for(int i=1; i<n; i=i+2){
		ans[i]=arr[pt];
		pt++;
	}
	for(int i=0; i<n; i=i+2){
		ans[i]=arr[pt];
		pt++;
	}
	int cnt=0;
	for(int i=1; i<n; i=i+2){
		if(i+1==n){
			continue;
		}
		if(ans[i]<ans[i-1] && ans[i]<ans[i+1]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}