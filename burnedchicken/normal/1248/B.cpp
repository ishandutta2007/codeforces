#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;

int main(){
	ll n,x,y,ans;
	cin >> n;
	ll a[n];
	loop(n) cin >> a[i];
	sort(a,a+n);
	x=y=0;
	loop(n){
		if(i<=n/2-1) x=x+a[i];
		else y=y+a[i];
	}
	ans=x*x+y*y;
	cout << ans << endl;
	return 0;
}