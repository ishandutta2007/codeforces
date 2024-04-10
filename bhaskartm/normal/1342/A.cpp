#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		long long int x, y;
		cin>>x>>y;
		long long int a, b;
		cin>>a>>b;
		long long int x1, y1;
		x1=min(x, y);
		y1=max(x, y);
		if(b>=2*a){
			cout<<a*(x1+y1)<<endl;
		}
		else{
			cout<<b*x1+(y1-x1)*a<<endl;
		}
	}
	
	
	return 0;
}