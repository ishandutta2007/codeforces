#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n , val = 0;
		cin>>n;
		vector<int> in(n);
		for(int i = 0 ; i < n ; i++) cin>>in[i];
		vector<int> l(3001 , 0) , r(3001 , 0);
		for(int i = 0 ; i < n ; i++){
			for(int t = n - 1 ; t > i ; t--){
				// cout<<l[in[t]]<<" "<<r[in[i]]<<endl;
				val += l[in[t]] * r[in[i]];
				r[in[t]]++;
			}
			l[in[i]]++;
			// r.clear();
			for(int t = n - 1 ; t > i ; t--) r[in[t]] = 0;
		}
		cout<<val<<endl;
	}
}