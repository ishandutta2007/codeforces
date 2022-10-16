#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t,n,a;
	cin>>t;
	while(t--){
		cin>>n;long long x=0;
		for(int i=0;i<n;i++){cin>>a;if(a<=2048)x+=a;} 
		if(x>=2048)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}