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
		vector<pair<int, int>>vec;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			vec.pb({x, i});
		}
		sort(vec.begin(), vec.end());
		if(vec[0].f==vec.back().f){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<vec[0].s+1<<" "<<vec.back().s+1<<endl;
		for(int i=1; i<n-1; i++){
			if(vec[i].f!=vec[0].f){
				cout<<vec[i].s+1<<" "<<vec[0].s+1<<endl;
			}
			else{
				cout<<vec[i].s+1<<" "<<vec.back().s+1<<endl;
			}
		}
	}
	return 0;
}