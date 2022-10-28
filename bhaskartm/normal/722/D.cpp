#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	set<int>s;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	while(1){
		bool b=0;
		auto it=s.end();
		it--;
		int val=(*it);
		int num=val;
		if(num==1){
			for(auto it=s.begin(); it!=s.end(); it++){
				cout<<((*it))<<" ";
			}
			return 0;
		}
		while(s.find(num)!=s.end() && num>=2){
			num=num/2;
		}
		if(s.find(num)==s.end()){
			b=1;
			s.insert(num);
			s.erase(val);
			continue;
		}
		if(b==0){
			for(auto it=s.begin(); it!=s.end(); it++){
				cout<<(*it)<<" ";
			}
			return 0;
		}
	}
	
	return 0;
}