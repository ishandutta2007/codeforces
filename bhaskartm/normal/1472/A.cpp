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
		int l, w, n;
		cin>>l>>w>>n;
		int ans=1;
		while(l%2==0){
			ans=ans*2;
			l=l/2;
		}
		while(w%2==0){
			ans=ans*2;
			w=w/2;
		}
		if(ans>=n){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}