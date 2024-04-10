#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n, k;
		cin>>n>>k;
		int arr[n];
		set<int>s;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			s.insert(arr[i]);
		}
		if(s.size()>k){
			cout<<-1<<endl;
			continue;
		}
		vector<int>v;
		for(auto it=s.begin(); it!=s.end(); it++){
			v.push_back((*it));
		}
		int x=(*(s.begin()));
		while(v.size()!=k){
			v.push_back(x);
		}
		vector<int>v1;
		while(1){
			if(v1.size()==10000){
				break;
			}
			for(int i=0; i<v.size(); i++){
				v1.push_back(v[i]);
				if(v1.size()==10000){
					break;
				}
			}
		}
		cout<<v1.size()<<endl;
		for(auto u:v1){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}