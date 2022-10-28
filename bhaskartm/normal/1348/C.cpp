#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		sort(s.begin(), s.end());
		if(s[0]!=s[k-1]){
			cout<<s[k-1]<<endl;
			continue;
		}
		if(s[0]==s[n-1]){
			int x=n/k;
			if(n%k!=0){
				x++;
			}
			for(int i=0; i<x; i++){
				cout<<s[0];
			}
			cout<<endl;
			continue;
		}
		int arr[26];
		for(int i=0; i<26; i++){
			arr[i]=0;
		}
		for(int i=0; i<s.size(); i++){
			arr[int(s[i]-'a')]++;
		}
		vector<pair<int, int>>v;
		for(int i=0; i<26; i++){
			if(arr[i]!=0){
				v.push_back({i, arr[i]});
			}
		}
		if(v[0].second>k){
			v[0].second-=(k-1);
			for(int i=0; i<v.size(); i++){
				for(int j=0; j<v[i].second; j++){
					cout<<char('a'+v[i].first);
				}
			}
			cout<<endl;
			continue;
		}
		if(v.size()==2){
			cout<<char('a'+v[0].first);
			int x=(v[1].second)/k;
			if((v[1].second)%k!=0){
				x++;
			}
			for(int i=0; i<x; i++){
				cout<<char('a'+v[1].first);
			}
			cout<<endl;
			continue;
		}
		if(v.size()>2){
			v[0].second-=(k-1);
			for(int i=0; i<v.size(); i++){
				for(int j=0; j<v[i].second; j++){
					cout<<char('a'+v[i].first);
				}
			}
			cout<<endl;
			continue;
		}
	}
	
	return 0;
}