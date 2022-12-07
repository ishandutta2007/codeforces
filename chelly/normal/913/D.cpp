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
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int a[N], t[N];
int cnt[10011];
vector<pair<int, int>> vec;
int main() {
	int n, T;
	scanf("%d%d", &n, &T);
	for(int i(0); i < n; i++) {
		scanf("%d%d", &a[i], &t[i]);
	}
	int le(0), ri(n);
	while(le != ri) {
		int mid = (le + ri + 1) / 2;
		memset(cnt, 0, sizeof(cnt));
		for(int i(0); i < n; i++) {
			if(a[i] >= mid) {
				cnt[t[i]]++;
			}
		}
		int rmn(mid);
		LL tot = 0;
		for(int i(0); i <= 10000 && rmn; i++) {
			tot += min(rmn, cnt[i]) * (LL)i;
			rmn -= min(rmn, cnt[i]);
		}
		if(rmn == 0 && tot <= T) {
			le = mid;
		}else ri = mid - 1;
	}
	printf("%d\n%d\n", le, le);
	for(int i(0); i < n; i++) {
		if(a[i] >= le) {
			vec.push_back({t[i], i});
		}
	}
	sort(vec.begin(), vec.end());
	for(int i(0); i < le; i++) printf("%d%c", vec[i].second + 1, i == le - 1 ? '\n' : ' ');
	if(le == 0) printf("\n");
}