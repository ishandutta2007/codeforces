#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e9;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int g;
	cin>>g;
	while(g--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
	
		int val[2*n];
		for(int i=0; i<2*n; i++){
			
			val[i]=0;
		}
		
		
		for(int i=0; i<n; i++){
			val[arr[i]-1]=1;
		}
		int maxi=0;
		int vals=0;
		for(int i=0; i<2*n; i++){
			if(val[i]==0){
				vals--;
			}
			else{
				vals++;
				
			}
			maxi=max(maxi, vals);
		}
		int maxi2=0;
		vals=0;
		for(int i=2*n-1; i>=0; i--){
			if(val[i]==0){
				vals--;
			}
			else{
				vals++;
			}
			maxi2=max(maxi2, vals);
		}
		cout<<max(0LL, n+1-maxi-maxi2)<<endl;
	}
	return 0;
}