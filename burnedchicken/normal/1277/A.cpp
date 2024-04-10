#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;

ll dgts(ll n){
	ll n1=n;
	ll x=0;
	while(n1>0){
		n1=n1/10;
		x++;
	}
	return x;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int q;
	cin >> q;
	loopi(noob,q){
		ll n,ans,x;
		cin >> n;
		ans=9*(dgts(n)-1);
		x=1;
		loop(dgts(n)) x*=10;
		x--;
		x/=9;
		ans+=n/x;
		cout << ans << "\n";
	}
	return 0;
}