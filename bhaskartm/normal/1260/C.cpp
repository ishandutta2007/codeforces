#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back

main() {
	int t;
	cin>>t;
	while(t--){
		int r, b, k;
		cin>>r>>b>>k;
		if(r==b){
			cout<<"OBEY"<<endl;
			continue;
		}
		int val2=__gcd(r, b);
		r=r/val2;
		b=b/val2;
		int r1=min(r, b);
		int b1=max(r, b);
		int bet=b1-1;
		int val;
		if(bet%r1==0){
			val=bet/r1;
		}
		else{
			val=(bet/r1)+1;
		}
		if(val>=k){
			cout<<"REBEL"<<endl;
			continue;
		}
		else{
			cout<<"OBEY"<<endl;
			continue;
		}
	}
	return 0;
}