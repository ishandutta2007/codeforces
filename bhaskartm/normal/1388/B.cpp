#include <bits/stdc++.h>
using namespace std;
 
#pragma optimize("-O3")
 
#define pb push_back
#define f first
#define s second
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ze=(n/4);
		int ei;
		if(n%4==0){
			ei=0;
		}
		else{
			ei=1;
		}
		int nin=n-ei-ze;
		for(int i=0; i<nin; i++){
			cout<<9;
		}
		for(int i=0; i<ei; i++){
			cout<<8;
		}
		for(int i=0; i<ze; i++){
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}