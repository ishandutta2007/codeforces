#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")
 
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define int long long int


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int l, r;
		cin>>l>>r;
		if(2*l<=r){
			cout<<l<<" "<<2*l<<endl;
			continue;
		}
		else{
			cout<<-1<<" "<<-1<<endl;
			continue;
		}
	}
	return 0;
}