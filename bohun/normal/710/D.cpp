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
#define int long long
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

int a1, a2, b1, b2, L, R;	
int Rx, Lx, Ry, Ly;

pair <int, int> euklides(int a, int b) {
	int ax = 1;
	int ay = 0;
	int bx = 0;
	int by = 1;
	while(b != 0) {
		int r = a / b;
		a -= r * b;
		ax -= r * bx;
		ay -= r * by;
		swap(a, b);
		swap(ax, bx);
		swap(ay, by);
	}
	return mp(ax, ay);
}
	
	
int32_t main() {
	ios;
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;

	Lx = ceil((ld) (L - b1) / a1);
	
	Rx = floor((ld) (R - b1) / a1);
	
	Ly = ceil((ld) (L - b2) / a2);
	
	Ry = floor((ld) (R - b2) / a2);
	
	int g = __gcd(a1, a2);
	int Prawo = b2 - b1;
	
	int xx = euklides(a1, a2).fi;
	int yy = -euklides(a1, a2).se;
	
	
	if(abs(Prawo) % g != 0) {
		cout << 0;
		return 0;
	}
	
	xx *= Prawo / g;
	yy *= Prawo / g;
	int A = a1;
	int B = -a2;
	
	Lx = floor((ld) (max((ll) 0, Lx) - xx) * g / B);
	
	Rx = ceil((ld) (Rx - xx) * g / B);
	
	Ly = floor((ld) -(max((ll) 0, Ly) - yy) * g / A);
	
	Ry = ceil((ld) -(Ry - yy) * g / A);
	
	swap(Lx, Rx);
	swap(Ly, Ry);
	
	int RR = min(Rx, Ry);
	int LL = max(Lx, Ly);
	
	cout << max((ll) 0, RR - LL + 1);
	
	
	return 0;
}