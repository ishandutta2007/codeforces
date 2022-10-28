#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, l, k;
	cin>>n>>l>>k;
	string arr[n];
	string s;
	cin>>s;
	multiset<int>se;
	for(int i=0; i<s.size(); i++){
		se.insert(int(s[i]-'a'));
	}
	int pointer=0;
	int check[n];
	for(int i=0; i<k; i++){
		check[i]=1;
	}
	for(int i=k; i<n; i++){
		check[i]=0;
	}
	
	while(!se.empty()){
		
		if(pointer==k-1){
			auto it=se.begin();
			int num=(*it);
			se.erase((it));
			arr[pointer]+=char(num+'a');
			pointer++;
			pointer=pointer%n;
			continue;
		}
		if(check[pointer]==1 && arr[pointer].size()==0){
			auto it=se.begin();
			int num=(*it);
			se.erase((it));
			arr[pointer]+=char(num+'a');
			pointer++;
			pointer=pointer%n;
			continue;
		}
		if(check[pointer]==0){
			auto it=se.end();
			it--;
			int num=(*it);
			se.erase((it));
			arr[pointer]+=char(num+'a');
			pointer++;
			pointer=pointer%n;
			continue;
		}
		if(check[pointer]==1 && arr[pointer][arr[pointer].size()-1]!=arr[k-1][arr[k-1].size()-1]){
			check[pointer]=0;
			continue;
		}
		if(check[pointer]==1 && arr[pointer][arr[pointer].size()-1]==arr[k-1][arr[k-1].size()-1]){
			auto it=se.begin();
			int num=(*it);
			se.erase((it));
			arr[pointer]+=char(num+'a');
			pointer++;
			pointer=pointer%n;
			continue;
		}
	}
	vector<string>v1;
	for(int i=0; i<k-1; i++){
		v1.push_back(arr[i]);
	}
	vector<string>v2;
	for(int i=k; i<n; i++){
		v2.push_back(arr[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(auto u:v1){
		cout<<u<<endl;
	}
	cout<<arr[k-1]<<endl;
	for(auto u:v2){
		cout<<u<<endl;
	}
	return 0;
}