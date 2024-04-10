#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int a, b, c;
	cin>>a>>b>>c;
	if(a==b){
		cout<<2*a+2*c;
		return 0;
	}
	else{
		cout<<2*c+2*(min(a, b))+1;
		return 0;
	}
	return 0;
}