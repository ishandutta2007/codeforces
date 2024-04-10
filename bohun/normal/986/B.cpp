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

const int nax = 1000005, inf = 1e9;

int n;
int odw[nax], go[nax], a, ile;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a;
		go[a] = i;
	}
	
	for(int i = 1; i <= n; ++i) {
		int A = i;
		int B = i;
		if(odw[i])
			continue;
		odw[B] = 1;
		B = go[B];
		while(A != B) {
			odw[B] = 1;
			B = go[B];
		}
		
		++ile;
	}
	
	ile = n - ile;
	
	if(n % 2 == 0) {
		if(ile % 2 == 0) {
			cout << "Petr";
		}
		else {
			cout << "Um_nik";
		}
	}
	else {
		if(ile % 2 == 0) {
			cout << "Um_nik";
		}
		else {
			cout << "Petr";
		}
	}	
		
	
				
	
	
	
	
	
	
	
	
	
	
				
	
	
	return 0;
}