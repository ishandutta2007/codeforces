#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		if((n%2)==0 && (2*k)>n){
			cout<<-1<<endl;
			continue;
		}
		if((n%2)==1 && 2*k>n+1){
			cout<<-1<<endl;
			continue;
		}
		vector<int>vec;
		char ans[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ans[i][j]='.';
			}
		}
		for(int i=0; i<k; i++){
			ans[2*i][2*i]='R';
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}