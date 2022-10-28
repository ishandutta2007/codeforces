#include <bits/stdc++.h>
using namespace std;
string s, t;
int arr[200005];

bool f(int x){
	bool che[s.size()];
	for(int i=0; i<s.size(); i++){
		che[i]=1;
	}
	for(int i=0; i<x; i++){
		che[arr[i]-1]=0;
	}
	
	int pointer=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]==t[pointer] && che[i]==1){
			pointer++;
			if(pointer==t.size()){
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin>>s>>t;
	for(int i=0; i<s.size(); i++){
		cin>>arr[i];
	}
	int ans=-1;
	int lo=0;
	int hi=s.size();
		
	while(lo<=hi){
		int mid=(lo+hi)/2;
		
		if(f(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<ans;
	return 0;
}