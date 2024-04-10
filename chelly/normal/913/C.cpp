#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 1000033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
LL a[333], num[333];
int main() {
	LL n, l;
	cin >> n >> l;
	for(int i(0); i < n; i++) {
		cin >> a[i];
	}
	for(int i(0); i < n; i++) {
		for(int j(0); j < i; j++) {
			a[i] = min(a[i], a[j] << i - j);
		}
		for(int k(i + 1); k < n; k++)
			a[i] = min(a[i], a[k]);
	}
	for(int i(0); i < n; i++) {
		if(l & (1 << i)) {
			l -= 1 << i;
			num[i] = 1;
		}
	}
	if(l != 0) {
		num[n - 1] += l / (1 << n - 1);
	}
	LL ans = 1ll << 62;
	LL cur = 0;
	for(int i(n - 1); i >= 0; i--) {
		ans = min(ans, cur + (num[i] + 1) * a[i]);
		cur += num[i] * a[i];
	}
	ans = min(ans, cur);
	cout << ans << endl;

}