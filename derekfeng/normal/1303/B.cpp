#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll n,g,b;
int main(){
	cin>>T;
	while (T--){
		cin>>n>>g>>b;
		ll nn=(n+1)/2,now;
		if (nn%g==0) now=(nn/g-1)*(g+b)+g;
		else now=(nn/g)*(g+b)+nn%g;
		cout<<max(now,n)<<"\n";
	}
}