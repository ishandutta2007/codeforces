#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	string t;
	cin>>t;
	int x=0;
	int y=0;
	int ans=0;
	for(int i=0; i<n; i++){
		if(y-x>1e13){
			ans+=(n-i)*k;
			cout<<ans;
			return 0;
		}
		if(s[i]=='a'){
			x=2*x;
		}
		else{
			x=2*x+1;
		}
		if(t[i]=='a'){
			y=2*y;
		}
		else{
			y=2*y+1;
		}
		ans+=min(k, y-x+1);
		
	}
	cout<<ans<<endl;
	return 0;
}