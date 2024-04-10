#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void fill(tint i, tint j, vvi& xored) {
	int n = xored.size();
	vi dx = {-1,1,0,0}, dy = {0,0,-1,1};
	forn(d, 4) {
		tint ni = i+dx[d], nj = j+dy[d];
		if(ni >= 0 && ni < n && nj >= 0 && nj < n) xored[ni][nj] = 1;
	}
}

int main() {
	int T;
	cin >> T;
	forn(tc, T) {
		tint n;
		cin >> n;
		vvi a(n, vi(n));
		forn(i, n) forn(j, n) {
			cin >> a[i][j];
		}
		tint ans = 0;
		
		{
			vvi xored(n, vi(n, 0));
			forn(j, n) {
				if(j%4 == 0) {
					fill(0, j, xored);
					ans ^= a[0][j];
				}
			}
			forsn(i, 1, n) forn(j, n) if((i+j)%2 == 0 && xored[i-1][j] == 0) {
				fill(i, j, xored);
				ans ^= a[i][j];
			}
		}
		
		forn(i, n) reverse(a[i].begin(), a[i].end());
		{
			vvi xored(n, vi(n, 0));
			forn(j, n) {
				if(j%4 == 0) {
					fill(0, j, xored);
					ans ^= a[0][j];
				}
			}
			forsn(i, 1, n) forn(j, n) if((i+j)%2 == 0 && xored[i-1][j] == 0) {
				fill(i, j, xored);
				ans ^= a[i][j];
			}
		}
		cout << ans << endl;
	}
}