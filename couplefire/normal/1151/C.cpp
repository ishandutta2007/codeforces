#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int p=1e9+7;
 
inline int calc(ll n){
	ll sx=0,sy=0,*x=&sx,*y=&sy;
	for (ll k=1;n>=k;k<<=1){
		*x+=k; n-=k; swap(x,y);
	}
	*x+=n; sx%=p,sy%=p;
	return (sx*sx+(sy+1)*sy)%p;
}
 
int main(){
	ll l,r; cin>>l>>r;
	cout<<(calc(r)-calc(l-1)+p)%p;
	return 0;
}