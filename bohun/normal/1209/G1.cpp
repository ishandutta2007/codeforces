#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
using namespace std;
using namespace __gnu_pbds;
const int nax = 2e5 + 111;

int n, q;
int a[nax];
vector <int> col;
int maxi[nax];
bool byl[nax];
int res = 0;
int ILE[nax];

int main() {
	ios;
	cin >> n >> q;
	FOR(i, 1, n) {
		cin >> a[i];
		maxi[a[i]] = i;
		ILE[a[i]] += 1;
	}
	
	for(int i = 1; i <= n;) {
		int j = i + 1;
		int R = maxi[a[i]];
		col.pb(a[i]);
		while(j <= R) {
			if(!byl[a[j]]) {
				byl[a[j]] = 1;
				col.pb(a[j]);
				R = max(R, maxi[a[j]]);
			}
			j += 1;
		}
		
		j -= 1;
		
		int e = 0;
		for(auto it: col) 
			e = max(e, ILE[it]);
		col.clear();
		res += j - i + 1 - e;
		i = j + 1;
	}
	
	cout << res;
		
		
	
	
	
	
	
	return 0;
}