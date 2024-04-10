#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;
 
ll bnr(ll n){
	ll k=0;
	while(n>0){
		if(n%2==1){
			n--;
			k++;
		}
		n=n/2;
	}
	return k;
}
 
int main(){
	ll n,p,ans;
	cin >> n >> p;
	for(int i=1; i>=0; i++){
		n=n-p;
		if(n<=0){
			cout << -1 << endl;
			return 0;
		}
		if(bnr(n)<=i&&n>=i){
			ans=i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}