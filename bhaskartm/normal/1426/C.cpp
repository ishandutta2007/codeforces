#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int f(int n, int x){
	if(n<=x){
		return 0;
	}
	n--;
	return (n/x);
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		int mini=1e9;
		for(int i=1; i<65000; i++){
			mini=min(mini, (i-1)+f(n, i));
		}
		cout<<mini<<endl;
	}
	return 0;
}