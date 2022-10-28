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
		int x[n];
		int y[n];
		for(int i=0; i<n; i++){
			cin>>x[i]>>y[i];
		}
		bool b=0;
		for(int i=0; i<n; i++){
			bool che=1;
			for(int j=0; j<n; j++){
				if(k<abs(x[i]-x[j])+abs(y[i]-y[j])){
					che=0;
					break;
				}
			}
			if(che==1){
				b=1;
				break;
			}
		}
		if(b){
			cout<<1<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}