#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

int t,s,n,k;

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>s>>n>>k;
		if(s<k){cout<<"no\n";goto res;}
		else if(s==k){cout<<"yes\n";goto res;}
		else {
			s++,n++;
			int x=(s/k/2+1)*(s%k)+(s/k+1)/2*(k-s%k);
			if(n>x)cout<<"yes\n";
			else cout<<"no\n";
		}
		res:;
	}
}