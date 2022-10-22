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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
const int nax = 2e5 + 5;
int t;
string xd;
int PL[nax];
int PR[nax];
int PU[nax];
int PD[nax];
int SL[nax];
int SR[nax];
int SU[nax];
int SD[nax];
int PX[nax];
int PY[nax];

int x, y;
int L, R, D, U;

void akt(char c) {
	if(c == 'W')
		++y;
	if(c == 'S')
		--y;
	if(c == 'A')
		--x;
	if(c == 'D')
		++x;
	L = min(L, x);
	R = max(R, x);
	D = min(D, y);
	U = max(U, y);
}

ll daj(int i, int xx, int yy) {
	int LL = min(PL[i], xx + PX[i] + SL[i + 1]);
	int RR = max(PR[i], xx + PX[i] + SR[i + 1]);
	int DD = min(PD[i], yy + PY[i] + SD[i + 1]);
	int UU = max(PU[i], yy + PY[i] + SU[i + 1]);
	ll ans = 1e18;
	ans = min(ans, (ll) (RR - LL + 1) * (UU - DD + 1));
	return ans;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> xd;
		FOR(i, 0, ss(xd) + 2) {
			PL[i] = 0;
			PR[i] = 0;
			PU[i] = 0;
			PD[i] = 0;
			PX[i] = 0;
			PY[i] = 0;
			SL[i] = 0;
			SR[i] = 0;
			SU[i] = 0;
			SD[i] = 0;
		}
			
		x = y = 0;
		L = R = D = U = 0;
		FOR(i, 0, ss(xd) - 1) {
			akt(xd[i]);
			PL[i + 1] = L;
			PR[i + 1] = R;
			PU[i + 1] = U;
			PD[i + 1] = D;
			PX[i + 1] = x;
			PY[i + 1] = y;
		}
		L = R = D = U = 0;
		for(int i = ss(xd) - 1; 0 <= i; --i) {
			int xx = 0, yy = 0;
			if(xd[i] == 'W')
				yy = 1;
			if(xd[i] == 'S')
				yy = -1;
			if(xd[i] == 'A')
				xx = -1;
			if(xd[i] == 'D')
				xx = 1;
			SL[i + 1] = min({xx, 0, SL[i + 2] + xx});
			SR[i + 1] = max({xx, 0, SR[i + 2] + xx});
			SU[i + 1] = max({yy, 0, SU[i + 2] + yy});
			SD[i + 1] = min({yy, 0, SD[i + 2] + yy});
			//cat(SD[i + 1]);
			//cat(SU[i + 1]);
		}
		ll ans = 1e18;
		ans = 1e18;
		FOR(i, 0, ss(xd)) {
			ans = min(ans, daj(i, 0, 1));
			ans = min(ans, daj(i, 1, 0));
			ans = min(ans, daj(i, 0, -1));
			ans = min(ans, daj(i, -1, 0));
		}
		
		cout << ans << endl;
			
			
		
	}
	
	
	
 
    return 0;
}