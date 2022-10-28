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
		if(n==1){
			cout<<9<<endl;
			continue;
		}
		if(n==2){
			cout<<98<<endl;
			continue;
		}
		cout<<98;
		int val=9;
		for(int i=0; i<n-2; i++){
			cout<<val;
			val=(val+1)%10;
		}
		cout<<endl;
	}
	return 0;
}