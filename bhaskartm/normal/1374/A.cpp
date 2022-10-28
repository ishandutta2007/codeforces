#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define endl '\n'
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int x, y, n;
		cin>>x>>y>>n;
		cout<<y+x*((n-y)/x)<<endl;
	}
	
	return 0;
}