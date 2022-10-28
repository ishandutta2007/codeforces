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
		bool che=0;
		while(n--){
			int a, b, c, d;
			cin>>a>>b>>c>>d;
			if(b==c){
				che=1;
			}
		}
		if(che && (m%2==0)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}