#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		int num=(n/k);
		if(m<=num){
			cout<<m<<endl;
			continue;
		}
		else{
			cout<<num-ceil(((1.0)*(m-num)/(k-1)))<<endl;
			continue;
		}
	}
	return 0;
}