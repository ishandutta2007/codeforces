#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	vector<long long int>v;
	long long int x=4;
	for(long long int i=2; i<32; i++){
		
		v.push_back(x-1);
		x=x*2;
	}
	
	for(int g=0; g<t; g++){
		long long int val;
		cin>>val;
		for(auto u:v){
			if(val%u==0){
				cout<<(val/u)<<endl;
				break;
			}
		}
	}
	return 0;
}