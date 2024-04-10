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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int mod = 1e9 + 7, nax = 200005;
int n;
int t[nax];
int pos = -1;


int main() {
	ios
	cin >> n;
	FOR(i, n)
		cin >> t[i];
	for(int i = 1; i <= n; ++i) {
		if(t[i] == n)
			pos = i;
	}
	int l = 1e9 + 1;
	for(int j = pos+ 1; j <= n; ++j) {
		if(l < t[j]) {
			cout << "NO";
			return 0;
		}
		l = t[j];
	}
	l = 1e9 + 5;
	for(int j = pos - 1; 1 <= j; --j) {
		if(l < t[j]) {
			cout << "NO";
			return 0;
		}
		l = t[j];
	}
	cout << "YES";
	
	
	
	
	return 0;
}