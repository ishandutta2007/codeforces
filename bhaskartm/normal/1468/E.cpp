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
		int a[4];
		for(int i=0; i<4; i++){
			cin>>a[i];
		}
		int maxi=0;
		sort(a, a+4);
		maxi=max(maxi, a[0]*a[2]);
		cout<<maxi<<endl;
	}
	return 0;
}