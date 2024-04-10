#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// writer: w33z8kqrqk8zzzx33
#include <cstdio>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
//#define int ll
const int MOD = 1000000007;

int ar[100005];

signed main() {
	int n, m; scanf("%d%d", &n, &m);
	rep1(i, n) scanf("%d", &ar[i]);
	while(m--) {
		int o, l, r, x; scanf("%d%d%d%d", &o, &l, &r, &x);
		int* pt = &ar[l]; r -= l - 1;
		if(o == 1) {
			while(r & 3) {
				r--;
				pt[r] -= (pt[r] > x) ? x : 0;
			}
			r >>= 2;
			while(r--) {
				pt[0] -= (pt[0] > x) ? x : 0;
				pt[1] -= (pt[1] > x) ? x : 0;
				pt[2] -= (pt[2] > x) ? x : 0;
				pt[3] -= (pt[3] > x) ? x : 0;
				pt += 4;
			}
		} else {
			int a0 = 0, a1 = 0, a2 = 0, a3 = 0;
			while(r & 3) {
				r--;
				a0 += pt[r] == x;
			}
			r >>= 2;
			while(r--) {
				a0 += pt[0] == x;
				a1 += pt[1] == x;
				a2 += pt[2] == x;
				a3 += pt[3] == x;
				pt += 4;
			}
			printf("%d\n", a0+a1+a2+a3);
		}
	}
}