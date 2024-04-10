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
const int nax = 500000 + 111, p = 43, mod = 1e9 + 7, pp = 37;

		
int main() {
	int res = 0;
	int maska = (1 << 7);
	cout << "? ";
	FOR(i, 1, 100)
		cout << (1 << 7) * i << " ";
	cout << endl;
	fflush(stdout);
	int x;
	cin >> x;
	res = ((maska - 1) & x);
	maska = 0;
	cout << "? ";
	FOR(i, 1, 100) 
		cout << i << " ";
	cout << endl;
	fflush(stdout);
	cin >> x;
	res |= (x & ((1 << 14) - (1 << 7)));
	cout << "! " << res;
	
	
	
	return 0;
}