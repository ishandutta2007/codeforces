#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int val=0;
		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			if(u==x || v==x){
				val++;
			}
		}
		if(n==1){
			cout<<"Ayush"<<endl;
			continue;
		}
		if(val==1){
			cout<<"Ayush"<<endl;
			continue;
		}
		if(n%2==0){
			cout<<"Ayush"<<endl;
			continue;
		}
		cout<<"Ashish"<<endl;
	}
	return 0;
}