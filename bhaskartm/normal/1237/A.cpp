#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define int long long int 
main() {
	int n;
	cin>>n;
	vector<int>odd;
	vector<int>vals;
	int sum=0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(abs(x)%2==1){
			odd.pb(i);
		}
		if(x>=0){
			vals.pb(x/2);
			sum+=(x/2);
		}
		else{
			vals.pb(((x-1)/2));
			sum+=((x-1)/2);
		}
		
	}
	
	for(int i=0; i<odd.size(); i++){
		if(sum==0){
			for(int j=0; j<vals.size(); j++){
				cout<<vals[j]<<endl;
			}
			return 0;
		}
		int j=odd[i];
		vals[j]++;
		sum++;
	}
	for(int j=0; j<vals.size(); j++){
				cout<<vals[j]<<endl;
			}
			return 0;
	return 0;
}