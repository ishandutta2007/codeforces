#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define int long long int
#define pb push_back
#define endl '\n'

int f(int n){
	int nn=n;
	int sum=0;
	while(nn!=0){
		sum+=(nn%10);
		nn=nn/10;
	}
	return sum;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		
		int n, s;
		cin>>n >>s;
		vector<int>v;
		int nn=n;
		while(nn!=0){
			v.pb(nn%10);
			nn=nn/10;
		}
	
		if(f(n)<=s){
			cout<<0<<endl;
			continue;
		}
		int po=1;
		int mini=1e18;
		for(int i=0; i<v.size(); i++){
			po=po*10;
			int nn=(n%po);
			int inc=po-nn;
			if(f(n+inc)<=s){
				mini=min(mini, inc);
			}
		}
		cout<<mini<<endl;
	}
	return 0;
}