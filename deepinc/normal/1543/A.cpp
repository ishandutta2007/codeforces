#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;cin>>t;while(t--){
		ll a,b;cin>>a>>b; if(a>b)swap(a,b);
		if(a==b)printf("0 0\n");
		else printf("%lld %lld\n",b-a,min(a%(b-a),(b-a)-a%(b-a)));
	}
}