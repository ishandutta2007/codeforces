#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		long long int a, b, q;
		cin>>a>>b>>q;
		long long int a1=min(a, b);
		long long int b1=max(a, b);
		long long int lc=(a1*b1)/__gcd(a1, b1);
		for(int j=0; j<q; j++){
			long long int l, r;
			cin>>l>>r;
			long long int ans1=0;
			long long int ans2=0;
			for(int i=0; i<b1; i++){
				ans1=ans1+((r-i)/lc)+1;
				ans2=ans2+((l-1-i)/lc)+1;
			}
			
			if(r<b1){
				ans1=r+1;
			}
			if(l<b1){
				ans2=l;
			}
			
			cout<<(r-l+1)-(ans1-ans2)<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}