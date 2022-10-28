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
		int n;
		cin>>n;
		
		int last=1;
		int ans=0;
		int rem=n;
		while(1){
			if(((last*(last+1))/2)<=rem){
				rem-=(((last*(last+1))/2));
				ans++;
				last=2*last+1;
			}
			else{
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}