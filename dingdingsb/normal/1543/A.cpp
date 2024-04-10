#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b;
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==b)
			puts("0 0");
		else{
			int x=min(a,b),y=max(a,b);
			int _;
			printf("%lld ",_=y-x);
			printf("%lld\n",min(x-(x/_)*_,(x/_)*_+_-x));
		}
	}
	return 0;
}