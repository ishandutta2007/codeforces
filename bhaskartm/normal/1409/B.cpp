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
	int iter=0;
	while(t--){
		iter++;
		int a, b, x, y, n;
		cin>>a>>b>>x>>y>>n;
		if((a-x)+(b-y)<=n){
			cout<<x*y<<endl;
			continue;
		}
		int diff1=a-x;
		int diff2=b-y;
		int val1, val2;
		if(n>diff1){
			val1=x*(b-(n-diff1));
		}
		else{
			val1=(a-n)*b;
		}
		if(n>diff2){
			val2=y*(a-(n-diff2));
		}
		else{
			val2=(b-n)*a;
		}
		cout<<min(val1, val2)<<endl;
	}
	return 0;
}