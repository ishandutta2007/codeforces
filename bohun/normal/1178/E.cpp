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
const int nax = 1000001, mod = 998244353;
char s[nax];
int t[nax];
int n;
vector <int> v, a[3], b[3];
vector <int> P, K;

void wywal(int x) {
	for(int i = 0; i <= 2; ++i)
		while(ss(a[i]) && x >= a[i][0])
			a[i].pop_back();
}
void wywal2(int x) {
	for(int i = 0; i <= 2; ++i)
		while(ss(b[i]) && x <= b[i][0])
			b[i].pop_back();
}

		

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if(n <= 3) {
		cout << s[1];
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		t[i] = s[i] - 'a';
	int i = 1;
	for(;;) {
		int kon = n - i + 1;
		if(i > kon)
			break;
		if(ss(P) == n / 2 / 2) {
			P.pb(i);
			break;
		}
		a[t[i]].pb(i);
		if(ss(b[t[i]]) != 0) {
			int KON = b[t[i]][0];
			wywal(i);
			wywal2(kon);
			P.pb(i);
			K.pb(KON);
		}
		b[t[kon]].pb(kon);
		if(ss(a[t[kon]]) != 0) {
			int POCZ = a[t[kon]][0];
			wywal(POCZ);
			wywal2(kon);
			P.pb(POCZ);
			if(POCZ != kon)
			K.pb(kon);
		}
		++i;
	}
	for(auto it: P)
		cout << s[it];
	reverse(K.begin(), K.end());
	for(auto it: K)
		cout << s[it];
			
		
		
		
	
	
	
	
	
	
	
	
	return 0;
}