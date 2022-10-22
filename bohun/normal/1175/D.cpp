#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 3e5 + 5, pod = (1 << 17), inf = 1e9 + 5;

ll n, k;
ll t[nax];
ll pref[nax];
ll sum, ans;	
multiset <ll> s;	

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	cin >> n >> k;
	for(int i = 1; n >= i; ++i) {
		cin >> t[i];
		pref[i] = pref[i - 1] + t[i];
		sum += t[i];
		if(i != n)
		s.insert(-pref[i]);
	}
	ans = k * sum;
	for(int i = 1; k - 1 >= i; ++i) {
		ans += *--s.end();
		s.erase(--s.end());
	}
	
	cout << ans;
	
	
	
	
	
		
	
    return 0;
}