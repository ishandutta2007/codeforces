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
		if(n<31){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		int val=n-30;
		if(val==6 || val==10 || val==14){
			cout<<6<<" "<<10<<" "<<15<<" "<<n-31<<endl;
			continue;
		}
		else{
			cout<<6<<" "<<10<<" "<<14<<" "<<n-30<<endl;
			continue;
		}
	}
	return 0;
}