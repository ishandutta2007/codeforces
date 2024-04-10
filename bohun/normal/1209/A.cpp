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

const int nax = 1e5 + 111;

int n, a[nax];
bool byl[nax];
int res;

int main() {
	ios;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	FOR(i, 1, n) {
		if(byl[i])
			continue;
		res += 1;
		FOR(j, i + 1, n)
			if(a[j] % a[i] == 0)
				byl[j] = 1;
	}
	cout << res;
	
	
	
	
	return 0;
}