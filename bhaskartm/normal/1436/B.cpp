#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


bool pr(int x){
	bool b=1;
	for(int j=2; j*j<=x; j++){
		if(x%j==0){
			return 0;
		}
	}
	return 1;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans[n][n];
		int val=-1;
		for(int i=4; i<=100000; i++){
			if(!pr(i) && pr(n-1+i)){
				val=i;
				break;
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j){
					ans[i][j]=val;
				}
				else{
					ans[i][j]=1;
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}