#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
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
		int n;
		cin>>n;
		if(n%2==1){
			cout<<(n+1)/2<<endl;
		}
		else{
			cout<<(n/2)+1<<endl;
		}
	}
	return 0;
}