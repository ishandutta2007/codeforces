#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")
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
		int m, d, w;
		cin>>m>>d>>w;
		int upp=(min(d, m))-1;
		int lc=(d-1)*(w)/(__gcd(d-1, w));
		if(lc==0){
			cout<<0<<endl;
			continue;
		}
		int mini=(lc/(d-1));
		int maxi=upp/mini;
		if(maxi==0){
			cout<<0<<endl;
			continue;
		}
		cout<<upp*maxi+maxi-((maxi*(maxi+1)*mini)/2)<<endl;
	}
	return 0;
}