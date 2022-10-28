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
		int x, y, k;
		cin>>x>>y>>k;
		int v1=k*(1+y)-1;
		int v2=x-1;
		if(v1%v2==0){
			cout<<k+(v1/v2)<<endl;
		}
		else{
			cout<<k+1+(v1/v2)<<endl;
		}
	}
	return 0;
}