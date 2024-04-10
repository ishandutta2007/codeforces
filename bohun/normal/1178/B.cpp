#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int nax = 1000001;
char s[1000001];
int pref[nax];
int suf[nax];
ll ans = 0;
int n;

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	
	for(int i = 1; i <= n; ++i) {
		pref[i] += pref[i - 1];
		if(i > 1 && s[i] == 'v' && s[i] == s[i - 1])
			++pref[i];
	}
	for(int i = n; 1 <= i; --i) {
		suf[i] += suf[i + 1];
		if(i < n && s[i] == 'v' && s[i] == s[i + 1])
			++suf[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		if(s[i] == 'o') {
			ans += (ll) pref[i - 1] * suf[i + 1];
		}
	}
	cout << ans;
	
	
	
	
	
	
	return 0;
}