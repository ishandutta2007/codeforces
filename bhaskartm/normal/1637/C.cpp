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
		vector<int>vec;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(i==0 || (i==(n-1))){
				continue;
			}
			else{
				vec.pb(x);
			}
		}
		int sz=vec.size();
		if(sz==1 && vec[0]%2==1){
			cout<<-1<<endl;
			continue;
		}
		bool b=1;
		for(auto u:vec){
			if(u!=1){
				b=0;
			}
		}
		if(b){
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		for(auto u:vec){
			ans+=((u+1)/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}