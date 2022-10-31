#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a<=b&&a<=c){
		cout<<a*(n-1)<<endl;
	}else if (b<=a&&b<=c){
		cout<<b*(n-1)<<endl;
	}else{
		if (n==1){
			cout<<0<<endl;
		}else{
			int x =a;
			x = min(x,b);
			x = min(x,c);
			cout<<min(a,b)+x*(n-2)<<endl;
		}
	}
	return 0;
}