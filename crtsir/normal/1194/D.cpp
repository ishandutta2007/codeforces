#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k%3==0){
			if((n%(k+1))%3==0&&n%(k+1)!=k)
				cout<<"Bob\n";
			else
				cout<<"Alice\n"; 
		}else{
			if(n%3)
				cout<<"Alice\n";
			else
				cout<<"Bob\n";
		}
	}
}