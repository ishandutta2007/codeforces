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
		int a, b;
		cin>>a>>b;
		int ans=0;
		for(int i=30; i>=0; i--){
			if(((a>>i)&1)!=((b>>i)&1)){
				ans+=(1<<i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}