#include <bits/stdc++.h>
using namespace std;
#define int long long int

 main() {
	set<int>sizes;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=1; i<=500000; i++){
		sizes.insert(i);
	}
	for(int i=0; i<n; i++){
		int val=arr[i];
		for(int j=1; j<=2000; j++){
			sizes.insert(val/j);
		}
	}
	int mini=1000000000000000000;
	vector<int>v;
	sort(arr, arr+n);
	if(sizes.find(0)!=sizes.end()){
		sizes.erase(0);
	}
	
	for(auto it=sizes.begin(); it!=sizes.end(); it++){
		if((*it)<=arr[0]){
			
			v.push_back((*it));
		}
	}
	
	for(auto u:v){
		int ans=0;
		for(int i=0; i<n; i++){
			int num=arr[i]/u;
			int rem=arr[i]%u;
			
			if(rem>num){
				ans=1000000000000000000;
				break;
			}
			
			else{
				ans+=num-((num-rem)/(1+u));
			}
		}
		
		mini=min(mini, ans);
	}
	cout<<mini;
	
	return 0;
}