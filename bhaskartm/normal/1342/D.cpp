#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	int arr[k+1];
	for(int i=0; i<=k; i++){
		arr[i]=0;
	}
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		arr[x]++;
	}
	set<pair<int, int>>s;
	vector<vector<int>>v;
	v.resize(n);
	
	int cnt[k+1];
	cnt[0]=0;
	for(int i=1; i<=k; i++){
		cin>>cnt[i];
	}
	
	for(int i=k; i>0; i--){
		int val=arr[i];
		int maxi=cnt[i];
		while(val>0){
			int index=0;
			int len=0;
			if(!s.empty()){
				auto it=s.begin();
				len=(*it).first;
				index=(*it).second;
			}
			if(len>=maxi){
				int l=s.size();
				s.insert({1, l});
				v[l].push_back(i);
			}
			else{
				s.erase({len, index});
				s.insert({len+1, index});
				v[index].push_back(i);
			}
			val--;
		}
	}
	cout<<s.size()<<endl;
	for(int i=0; i<s.size(); i++){
		cout<<v[i].size()<<" ";
		for(auto u:v[i]){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}