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
		int n, k;
		cin>>n>>k;
		int x=0;
		while(n--){
			cout<<char('a'+x);
			x++;
			x=x%3;
		}
		cout<<endl;
	}
	return 0;
}