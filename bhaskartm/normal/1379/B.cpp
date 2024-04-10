#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int t;
	cin>>t;
	
	while(t--){
		int l, r, m;
		cin>>l>>r>>m;
		for(int a=l; a<=r; a++){
			int val;
			if(m<a){
				val=a-m;
			}
			else{
				val=min(m%a, a-(m%a));
			}
			if(val<=(r-l)){
				if(m<a){
					cout<<a<<" "<<r-val<<" "<<r<<endl;
					break;
				}
				else if(m%a<a-m%a){
					cout<<a<<" "<<l+val<<" "<<l<<endl;
					break;
				}
				else{
					cout<<a<<" "<<r-val<<" "<<r<<endl;
					break;
				}
			}
		}
	}
	return 0;
}