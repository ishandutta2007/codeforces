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

const int nax = 100005;

string a, b, c;
int A[30], B[30], C[30], D[30];

bool ok() {
	if(ss(a) > ss(b))
		return 0;
	int j = 0;
	bool ok = 1;
	for(int i = 0; i < ss(a); ++i) {
		while(j < ss(b) && a[i] != b[j])
			++j;
		if(j == ss(b))
			ok = 0;	
		++j;
	}
	return ok;
}
	
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		if(!ok()) {
			printf("NO\n");
			continue;
		}
		for(int i = 0; i < 26; ++i)
			A[i] = B[i] = C[i] = 0;
		for(auto it: a)
			A[it - 'a']++;
		for(auto it: b)
			B[it - 'a']++;
		for(auto it: c)
			C[it - 'a']++;
		bool ok = 1;
		for(int i = 0; i < 26; ++i) {
			D[i] = B[i] - A[i];
		}
		for(int i = 0; i < 26; ++i) {
			ok &= (C[i] >= D[i]);
		}
		if(ok) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		
		
	}
			
	
	

	return 0;
}