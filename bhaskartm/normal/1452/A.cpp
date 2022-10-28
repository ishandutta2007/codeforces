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
		int x, y;
		cin>>x>>y;
		if(x<y){
			swap(x, y);
		}
		int ans=0;
		ans+=2*y;
		x=x-y;
		if(x==0){
			cout<<ans<<endl;
			continue;
		}
		x--;
		ans++;
		ans+=(2*x);
		cout<<ans<<endl;
	}
	return 0;
}