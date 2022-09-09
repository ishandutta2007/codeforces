#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,t;
long long k,a[200005],g;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		g=0;bool f=0;
		rep(i,n){
			cin>>a[i];
		}
		rep(i,n){
			if(a[i]==k){
				f=1;break;
			}
		}
		if(f){
			puts("YES");
			continue;
		}
		rep(i,n-1){
			g=__gcd(g,abs(a[i]-a[n]));
		}
		if(g&&((k-a[n])%g==0)){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}