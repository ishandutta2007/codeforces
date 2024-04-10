#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
const int MN = 203, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int a[MN], dp[MN];
void uadd (int &aa, int b) {aa += b; if (aa >= MOD) aa -= MOD;}
int main() {
	int n,h;
	scanf ("%d %d",&n,&h);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",a+i);
		if (a[i] > h) return !printf ("0\n");
		a[i] = h-a[i]; 
		if (i>1&&abs(a[i]-a[i-1]) > 1) return !printf ("0\n");
	}
	if (a[1] > 1 || a[n] > 1) return !printf ("0\n");
	dp[1] = 1;int ret = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i-1]) {
			ret = ret * 1LL * (a[i]+1) % MOD;
		} else if (a[i] < a[i-1]){
			ret = ret * 1LL * a[i-1] % MOD;
		}
	}
	printf ("%d\n",ret);
    return 0;
}