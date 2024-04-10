#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;
	
int n;
int val[300001];
ll mask[300001];
vector <int> mst[62];

int sgn(ll x) {
	if(x > 0) return 1;
	if(x == 0) return 0;
	return -1;
}

int main() {
	ll S = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %lld", val + i, mask + i);
		S += val[i];
		for(int j =	61; 0 <= j; --j) {
			if(((1LL << j) & mask[i])) {
				mst[j].pb(i);
				break;
			}
		}
	}
	
	ll ans = 0;
	for(int i = 0; i < 62; ++i) {
		ll sum = 0;
		for(auto it : mst[i]) {
			ll maska = (ans & mask[it]);
			ll oo = 0;
			for(int j = 0; j < 62; ++j)
				oo += (((1LL << j) & maska) > 0);
			oo %= 2;
			if(oo == 0)
				sum += val[it];
			else
				sum -= val[it];
		}
		
		if(sgn(sum) == sgn(S))
			ans ^= (1LL << i);
	}
	printf("%lld", ans);
			
		
				
	
	
	return 0;
}