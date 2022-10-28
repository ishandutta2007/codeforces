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
		int n, x;
		cin>>n>>x;
		int ans=0;
		multiset<int>se;
		for(int i=0; i<n; i++){
			int y;
			cin>>y;
			se.insert(y);
		}
		while(!se.empty()){
			auto it=se.begin();
			int v1=(*it);
			auto it2=se.find(v1*x);
			if(it2==se.end()){
				ans++;
				se.erase(it);
				continue;
			}
			else{
				se.erase(se.find(v1));
				se.erase(se.find(v1*x));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}