#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int o=0;
		int e=0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(x%2==0){
				e++;
			}
			else{
				o++;
			}
		}
		if(o==0){
			cout<<"No"<<endl;
			continue;
		}
		if(e==0 && x%2==0){
			cout<<"No"<<endl;
			continue;
		}
		if(n==x && o%2==0){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		
	}
	return 0;
}