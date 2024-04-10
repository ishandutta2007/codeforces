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
const int nax = 2e5 + 11;
int T;
int n;
int a[nax];
int ile[11];
int col[nax];
string s;

int sum(int l, int r) {
	int res = 0;
	FOR(i, l, r)
		res += ile[i];
	return res;
} 

bool good(int x) {
	FOR(i, 0, 10)
		ile[i] = 0;
	
	FOR(i, 1, n)
		ile[a[i]] += 1;
	
	FOR(i, 1, n)
		col[i] = 0;
	
	int Last = -1;
	
	FOR(i, 1, n) {
		if(a[i] > x)
			continue;
		if(sum(0, a[i] - 1) == 0) {
			col[i] = 1;
			ile[a[i]] -= 1;
			Last = a[i];
		}
	}
	
	
	
	FOR(i, 1, n) {
		if(col[i])
			continue;
		
		if(Last > a[i])
			return 0;
		col[i] = 2;
		Last = a[i];
	}
	return 1;
}
		
	
	
	
	

int main() {
	
	cin >> T;
	while(T--) {
		cin >> n >> s;
		s = '3' + s;
		FOR(i, 1, n)
			a[i] = s[i] - '0';
		
		bool ok = 0;
		FOR(i, 0, 9) {
			if(good(i)) {
				ok = 1;
				break;
			}
		}
		
		if(!ok)
			cout << "-" << endl;
		else {
			FOR(i, 1, n)
				cout << col[i];
			cout << endl;
		}
	}
	
		
		
	
	
	return 0;
}