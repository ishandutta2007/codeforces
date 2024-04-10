#include<bits/stdc++.h>
using namespace std;
int n=0;
int main(){
	cin>>n;
	for(int i=n/2;i>=1;i--){
		int V=i,W=n-i;
		if(__gcd(V,W)==1){cout<<V<<" "<<W<<endl;break;}
	}
	return 0;
}