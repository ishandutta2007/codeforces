#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, r;
		cin>>n>>r;
		if(r>=n){
			cout<<1+(((n-1)*(n))/2)<<endl;
		}
		else{
			cout<<(r*(r+1))/2<<endl;
		}
	}
	return 0;
}