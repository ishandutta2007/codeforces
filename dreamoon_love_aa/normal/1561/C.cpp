//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define PB push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int MAX = 1e9, MOD = 1e9 + 7;

int main(){
	IOS;
	int t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n;
		vector<pair<ll, ll>> vp(n);
		for(ll i = 0;i < n;i++){
			cin >> k;
			vp[i].S = k;
			vp[i].F = 0;
			for(ll j = 1;j <= k;j++){
				ll a;
				cin >> a;
				vp[i].F = max(vp[i].F, a - j + 2);
			}
		}
		sort(vp.begin(), vp.end());
		ll add = 0, now = vp[0].F;
		for(ll i = 0;i < n - 1;i++){
			if(now + vp[i].S <= vp[i + 1].F){
				add += vp[i + 1].F - (now + vp[i].S);
				now += vp[i + 1].F - (now + vp[i].S);
			}
			now += vp[i].S;
		}
		cout << vp[0].F + add << endl;
	}
}