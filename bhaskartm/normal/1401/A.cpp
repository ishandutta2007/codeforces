#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		if(k>n){
			cout<<k-n<<endl;
			continue;
		}
		if(n%2 != k%2){
			cout<<1<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}