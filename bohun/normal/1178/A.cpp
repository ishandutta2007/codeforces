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

const int nax = 100005, mod = 1e9 + 7;		
int n;
int a[nax];
int ile = 0;

int main() {
	cin >> n;
	int sum = 0;
	int summ = 0;
	++ile;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(i > 1 && 2 * a[i] <= a[1]) {
			++ile;
			sum += a[i];
		}
		summ += a[i];
	}
	sum += a[1];
	if(sum > summ / 2) {
		cout << ile << endl;
		for(int i = 1; i <= n; ++i) {
			if((a[i] <= a[1] && a[i] * 2 <= a[1]) || i == 1) {
				cout << i << " ";
			}
		}
	}
	else {
		cout << 0;
	}
		
	
	
	
	
	
	return 0;
}