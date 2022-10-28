#include<bits/stdc++.h>
using namespace std;
int val[300000];


int main() {
	int n, x;
	cin>>n>>x;
	bool booly=true;
	if(x>=pow(2, n)){
		booly=false;
	}
	
	if(booly=false){
		vector<int>vec;
		for(int i=1; i<pow(2, n); i++){
			vec.push_back(i);
		}
		vector<int>final;
		if(vec.size()==0){
			cout<<0;
			return 0;
		}
		final.push_back(vec[0]);
		for(int i=1; i<vec.size(); i++){
			final.push_back(vec[i]^vec[i-1]);
		}
		cout<<final.size()<<endl;
		for(auto u:final){
			cout<<u<<" ";
		}
		return 0;
	}
	
	for(int i=1; i<pow(2, n); i++){
		if(i==x){
			val[i]=0;
			continue;
		}
		if(val[i]==0 && val[i^x]==1){
			continue;
		}
		val[i^x]=0;
		val[i]=1;
	}
	
	vector<int>vec;
	for(int i=1; i<pow(2, n); i++){
		if(val[i]==1){
			vec.push_back(i);
		}
	}
	if(vec.size()==0){
		cout<<0;
		return 0;
	}
	vector<int>f;
	f.push_back(vec[0]);
	
	for(int i=1; i<vec.size(); i++){
		f.push_back(vec[i]^vec[i-1]);
	}
	cout<<f.size()<<endl;
	for(auto u:f){
		cout<<u<<" ";
	}
	return 0;
}