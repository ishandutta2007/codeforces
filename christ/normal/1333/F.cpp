#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
const int MN = 5e3+5, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
bool prime (int n) {
	for (int i = 2; i * i <= n; i++) if (n%i==0) return 0;
	return 1;
}
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> pp;
	for (int i = 1; i <= n; i++) if (prime(i)) pp.push_back(i);
	int curp = 1, curv = pp.size(), ret=1; set<int> add;
	for (int i : pp) add.insert(i);
	for (int i = 2; i <= n; i++) {
		if (i <= curv) printf ("%d ",ret);
		else {
			ret = ++curp;
			if (prime(ret)) {
				for (int j = 1; j < pp.size()&&ret*1LL*pp[j]<=n&&pp[j]<=ret; j++) {
					++curv,add.insert(ret*pp[j]);
				}
			} else {
				int pf = -1;
				for (int j = 2; j * j <= ret; j++) if (ret%j==0) {
					pf = j;
					break;
				}
				for (int j = 1; j<pp.size()&&pp[j]<=pf&&ret*1LL*pp[j]<=n;j++) {
					++curv,add.insert(ret*pp[j]);
				}
			}
			printf ("%d ",ret);
		}
	}
	printf ("\n");
    return 0;
}