#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n;
		cin>>n;
		long long int ans=0;
		for(int i=1; i<(n/2); i++){
			ans=ans+pow(2, i);
		}
		ans=ans+pow(2, n);
		for(int i=(n/2); i<n; i++){
			ans=ans-pow(2, i);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}