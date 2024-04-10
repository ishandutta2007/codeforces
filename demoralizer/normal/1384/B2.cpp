#include "bits/stdc++.h"
using namespace std;

const int N = 3e5+5;
int d[N];


void solve(){
	int n,k,l;
	cin>>n>>k>>l;
	
	for(int i = 0 ;i < n ; i++){
		cin>>d[i];
	}
	
	int tim = 0; // minimum time
	
	for(int i=0;i<n;i++){
		if(d[i] > l){
			cout<<"No\n";
			return;
		}
		if(d[i] + k <= l){
			tim = 0;
		}
		
		int tide_depth = k - tim;
		tide_depth = abs(tide_depth);
		
		if(tide_depth + d[i] <= l){
			tim++;
			continue;
		}
		else{
			if(tim >= k){
				cout<<"No\n";
				return;
			}
			else{
				int reqd_tide = l - d[i]; // reqd_tide <= l - d[i]
				
				int reqd_time = k - reqd_tide;
				
				tim = reqd_time + 1;
				
				
			}
		}
		
	}
	
	cout<<"Yes\n";
	
	
}

int main(){
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}