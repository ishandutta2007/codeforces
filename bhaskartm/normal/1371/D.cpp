#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
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
		int arr[n][n];
		int val=k/n;
		int rem=k%n;
		bool b;
		if(rem>0){
			b=1;
		}
		else{
			b=0;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				arr[i][j]=0;
			}
		}
		int pt=0;
		for(int i=0; i<n; i++){
			int value=val;
			if(rem>0){
				value++;
				rem--;
			}
			for(int cn=0; cn<value; cn++){
				arr[i][pt]=1;
				pt++;
				pt=pt%n;
			}
		}
		
		
		
		if(b){
			cout<<2<<endl;
		}
		else{
			cout<<0<<endl;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}