#include <bits/stdc++.h>
using namespace std;
#define int long long int

map<int, bool>check;
map<int, int>gr;

int f(int v, int u){
	if(check[v]==1){
		return gr[v];
	}
	if(v==0){
		return 0;
	}
	int pointer=0;
	while((1LL<<(pointer+1))<=v){
		pointer++;
	}
	pointer++;
	
	set<int>s;
	
	for(int i=1; i<=pointer; i++){
		gr[((v>>i)|(((1LL<<(i-1))-1)&v))]=f(((v>>i)|(((1LL<<(i-1))-1)&v)), u);
		s.insert(gr[((v>>i)|(((1LL<<(i-1))-1)&v))]);
	}
	
	vector<int>vec;
	for(auto it=s.begin(); it!=s.end(); it++){
		vec.push_back((*it));
	}
	
	if(vec[vec.size()-1]==vec.size()-1){
		check[v]=1;
		gr[v]=vec.size();
	}
	else{
		for(int i=0; i<vec.size(); i++){
			if(vec[i]!=i){
				check[v]=1;
				gr[v]=i;
				break;
			}
		}
	}
	return gr[v];
}

main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	map<int, int>m[105];
	map<int, int>ma;
	for(int i=0; i<n; i++){
		int val=arr[i];
		for(int x=2; x*x<=val; x++){
			while(val%x==0){
				ma[x]=1;
				m[i][x]++;
				val=val/x;
			}
		}
		if(val!=1){
			m[i][val]++;
			ma[val]=1;
		}
	}
	int ans=0;
	for(auto it=ma.begin(); it!=ma.end(); it++){
		int mask=0;
		for(int i=0; i<n; i++){
			if(m[i][it->first]==0){
				continue;
			}
			else{
				mask=mask|(1LL<<(m[i][it->first]-1));
			}
		}
		
		gr[mask]=f(mask, mask);
	
		ans=ans^(gr[mask]);
	}
	
	if(ans==0){
		cout<<"Arpa"<<endl;
	}
	else{
		cout<<"Mojtaba"<<endl;
	}
	return 0;
}