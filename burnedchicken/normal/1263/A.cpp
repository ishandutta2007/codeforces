#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		ll r,g,b;
		cin >> r >> g >> b;
		ll x=max(max(r,g),b);
		ll ans;
		if(r+g+b<=2*x) ans=r+g+b-x;
		else ans=(r+g+b)/2;
		cout << ans << "\n";
	}
	return 0;
}