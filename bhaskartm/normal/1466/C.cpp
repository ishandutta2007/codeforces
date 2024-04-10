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
		string st;
		cin>>st;
		int n=st.size();
		int arr[n];
		for(int i=0; i<n; i++){
			arr[i]=st[i]-'a';
		}
		int ans=0;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(arr[1]==arr[0]){
			arr[1]=100;
			ans++;
		}
		for(int i=2; i<n; i++){
			if(arr[i]==arr[i-1] || arr[i]==arr[i-2]){
				arr[i]=100;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}