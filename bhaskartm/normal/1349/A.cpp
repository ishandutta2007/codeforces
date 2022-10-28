#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
int main() {
	int n;
	cin>>n;
	v.resize(200005);
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		vector<pair<int, int>>f;
		int val=arr[i];
		for(int x=2; x*x<=val; x++){
			while(val%x==0){
				val=val/x;
				if(f.size()==0 || f[f.size()-1].first!=x){
					f.push_back({x, 1});
				}
				else{
					int ti=f[f.size()-1].second;
					f.pop_back();
					f.push_back({x, ti+1});
				}
			}
		}
		if(val>1){
			f.push_back({val, 1});
		}
		for(int j=0; j<f.size(); j++){
			v[f[j].first].push_back(f[j].second);
		}
	}
	for(int i=0; i<=200000; i++){
		sort(v[i].begin(), v[i].end());
	}
	
	long long int ans=1;
	for(int i=2; i<=200000; i++){
		if(v[i].size()<=n-2){
			continue;
		}
		if(v[i].size()==n-1){
			ans=ans*(pow(i, v[i][0]));
			continue;
		}
		if(v[i].size()==n){
			
			ans=ans*(pow(i, v[i][1]));
		}
	}
	cout<<ans;
	return 0;
}