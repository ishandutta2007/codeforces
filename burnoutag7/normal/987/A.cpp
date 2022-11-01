#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
map<string,string> mp;
vector<string> v;
int cnt;
int main(){
	mp["purple"]="Power";
	mp["green"]="Time";
	mp["blue"]="Space";
	mp["orange"]="Soul";
	mp["red"]="Reality";
	mp["yellow"]="Mind";
	string s[6],t[6]={"Power","Time","Space","Soul","Reality","Mind"};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		s[i]=mp[s[i]];
	}
	for(int i=0;i<6;i++){
		bool k=0;
		for(int j=0;j<n;j++){
			if(t[i]==s[j]){
				k=1;
			}
		}
		if(!k){
			v.push_back(t[i]);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
		
	}
	return 0;
}