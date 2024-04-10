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
		int n, x;
		cin>>n>>x;
		if(n<=2){
			cout<<1<<endl;
			continue;
		}
		n=n-2;
		n--;
		cout<<(2+(n/x))<<endl;
	}
	return 0;
}