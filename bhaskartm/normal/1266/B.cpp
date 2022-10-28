#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define int long long int 
main() {
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int val=x%14;
		if(x>=15 && val>=1 && val<=6){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
			
		}
	}
	return 0;
}