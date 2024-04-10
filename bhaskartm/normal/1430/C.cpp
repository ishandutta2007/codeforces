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
		
		cout<<2<<endl;
		if(n==2){
			cout<<1<<" "<<2<<endl;
			continue;
		}
		cout<<n<<" "<<n-2<<endl;
		cout<<n-1<<" "<<n-1<<endl;
		for(int i=0; i<n-3; i++){
			cout<<n-i-1<<" "<<n-i-3<<endl;
		}
	}
	return 0;
}