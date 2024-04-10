#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll q,n;
	cin >> q;
	loop(q){
		cin >> n;
		ll a[n];
		loopi(j,n) cin >> a[j];
		sort(a,a+n);
		bool t=true;
		loopi(j,n-1){
			if(a[j+1]==a[j]+1){
				cout << 2 << endl;
				t=false;
				break;
			}
		}
		if(t) cout << 1 << endl;
	}
	return 0;
}