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
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int nax = 300005;

pair <ll, ll> hasz[nax], s[nax], pref[nax];
int t[nax], n, ile;

int ans = 0;

int bylo[nax];

bool daj(int l, int r) {
	ll A = pref[r].fi ^ pref[l - 1].fi;
	ll B = pref[r].se ^ pref[l - 1].se;
	return A == s[r - l + 1].fi && B == s[r - l + 1].se;
}
	

void go() {
	FOR(i, n)
		bylo[i] = 0;
	FOR(i, n) {
		if(t[i] != 1)
			continue;
		++ile;
		int maxi = 1;
		for(int j = i; j <= n; ++j) {
			if(t[j] == 1 && j > i)
				break;
			if(bylo[t[j]] == i || t[j] > n)
				break;
			maxi = max(maxi, t[j]);
			bylo[t[j]] = i;
			int R = j;
			int L = R - maxi + 1;
			if(L >= 1 && daj(L, R))
				ans++;
		}
	}
}
			
		

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;	
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		hasz[i].fi = (ll) rand() * rand();
		hasz[i].se = (ll) rand() * rand();
		s[i].fi = hasz[i].fi ^ s[i - 1].fi;
		s[i].se = hasz[i].se ^ s[i - 1].se;
	}
	
	for(int i = 1; i <= n; ++i) {
		pref[i].fi = pref[i - 1].fi ^ hasz[t[i]].fi;
		pref[i].se = pref[i - 1].se ^ hasz[t[i]].se;
	}
	
	go();
	reverse(t + 1, t + n + 1);
	for(int i = 1; i <= n; ++i) {
		pref[i].fi = pref[i - 1].fi ^ hasz[t[i]].fi;
		pref[i].se = pref[i - 1].se ^ hasz[t[i]].se;
	}
	go();
	cout << ans - ile / 2;
		
	
	
	
	
				
	
	
    return 0;
}