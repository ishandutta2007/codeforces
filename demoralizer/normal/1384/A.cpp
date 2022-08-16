#include "bits/stdc++.h"
using namespace std;

void solve(){
	string s = "utkarshutkarshutkarshutkarshutkarshutkarshutkarshutkarsh";
	int n;
	cin>>n;
	cout<<s<<"\n";
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		
		s[a]++;
		if(s[a] > 'z') s[a] = 'a';
		
		cout<<s<<"\n";
		
	}
	
}

int main(){
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}