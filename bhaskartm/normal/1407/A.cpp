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
		int n;
		cin>>n;
		int c0=0;
		int c1=0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(x==1){
				c1++;
			}
			else{
				c0++;
			}
				
		}
		if(c0>=c1){
			cout<<c0<<endl;
			for(int i=0; i<c0; i++){
				cout<<0<<" ";
			}
			cout<<endl;
			continue;
		}
		else{
			cout<<(c1/2)*2<<endl;
			for(int i=0; i<(c1/2)*2; i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}