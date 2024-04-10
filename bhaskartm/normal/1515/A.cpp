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
		int n, w;
		cin>>n>>w;
		vector<int>v;
		int su=0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			v.pb(x);
			su+=x;
		}
		if(su==w){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		int sx=0;
		sort(v.begin(), v.end());
		for(int i=0; i<n; i++){
			sx+=v[i];
			if(sx==w){
				swap(v[i], v[i+1]);
				break;
			}
		}
		for(auto u:v){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}