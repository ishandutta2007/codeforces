#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	set<int>s;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	vector<int>v;
	for(auto it=s.begin(); it!=s.end(); it++){
		v.push_back((*it));
	}
	int maxi=0;
	for(int i=v.size()-1; i>=0; i--){
		int val=v[i];
		if(val<=maxi){
			break;
		}
		for(int j=2; j*val<=2000000; j++){
			auto it=s.lower_bound(j*val);
			if(it!=s.begin()){
				it--;
			}
			int num=(*it);
			if(num<val){
				continue;
			}
			maxi=max(maxi, num%val);
			
		}
	}
	cout<<maxi;
	return 0;
}