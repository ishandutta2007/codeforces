#include <bits/stdc++.h>
using namespace std;
int T,s;
int main(){
	cin>>T;
	while(T--){
		cin>>s;
		int l=0,r=5001;
		while(r>l+1){
			int m=(l+r)/2;
			if(m*m<s)l=m;
			else r=m;
		}
		cout<<r<<"\n";
	}
}