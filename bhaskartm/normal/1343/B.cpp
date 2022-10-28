#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n;
		cin>>n;
		if(n%4!=0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		int x=2;
		for(int i=0; i<(n/2); i++){
			cout<<x<<" ";
			x=x+2;
		}
		x=1;
		for(int i=0; i<((n/2)-1); i++){
			cout<<x<<" ";
			x=x+2;
		}
		cout<<n+(n/2)-1<<endl;
	}
	return 0;
}