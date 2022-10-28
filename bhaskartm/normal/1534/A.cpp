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
		int n, m;
		cin>>n>>m;
		char arr[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		char a[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if((i+j)%2==0){
					a[i][j]='R';
				}
				else{
					a[i][j]='W';
				}
			}
		}
		char b[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if((i+j)%2==1){
					b[i][j]='R';
				}
				else{
					b[i][j]='W';
				}
			}
		}
		int che=1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j]!=a[i][j] && arr[i][j]!='.'){
					che=0;
				}
			}
		}
		if(che){
			cout<<"YES"<<endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cout<<a[i][j];
				}
				cout<<endl;
			}
			continue;
		}
		che=1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j]!=b[i][j] && arr[i][j]!='.'){
					che=0;
				}
			}
		}
		if(che){
			cout<<"YES"<<endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cout<<b[i][j];
				}
				cout<<endl;
			}
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}