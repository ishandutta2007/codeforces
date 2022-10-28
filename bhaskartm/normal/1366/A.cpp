#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		if(b>a){
			swap(a, b);
		}
		
		int gap=a-b;
		if(gap>=b){
			cout<<b<<endl;
			continue;
		}
		int ans=gap;
		int c=b-gap;
		int rem=c%3;
		ans=ans+2*(c/3);
		if(rem==2){
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}