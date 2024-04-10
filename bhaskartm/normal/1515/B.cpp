#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
map<int, bool>ma; 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1; i<=100000; i++){
		ma[2*i*i]=1;
		ma[4*i*i]=1;
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(ma[n]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}