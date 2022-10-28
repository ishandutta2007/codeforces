#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define  pb push_back
#define  f first
#define  s second

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%4==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}