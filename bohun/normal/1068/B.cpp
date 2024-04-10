#pragma GCC optimize("Ofast")
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

const int nax = 200005, inf = 1e9 + 1;



int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll a;
	int res = 0;
	cin >> a;
	for(ll i = 1; i * i <= a; ++i) {
		if(a % i == 0) {
			res++;
			if(i * i != a)
				res++;
		}
	}
	cout << res;
	
	
    return 0;
}