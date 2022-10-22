#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N,a,b;
		cin>>N>>a>>b;
		ll mcm=a*b/__gcd(a,b);
		ll mi=1000000;
		for(ll i=0;i<mcm;i++){
			if(i*b*5>N)break;
			mi=min(mi,(N-i*b*5)%a);
		}
		cout<<mi;
		return 0;
}