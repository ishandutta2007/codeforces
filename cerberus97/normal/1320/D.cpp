/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

int add(int a, int b, int mod) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int sub(int a, int b, int mod) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int mul(ll a, int b, int mod) {
	return (a * b) % mod;
}

int pwr(int x, int e, int mod) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x, mod);
		}
		x = mul(x, x, mod);
		e /= 2;
	}
	return res;
}

char t[N];

int get_hash(vector<int>& h, int base, int mod, vector<int>& cnt, int l, int r);

int main() {
	srand(time(0));
	fast_cin();
	int n; cin >> n;
	cin >> (t + 1);
	t[n + 1] = t[n] ^ '0' ^ '1';
	vector<int> cnt(n + 2, 0);
	vector<int> mod = {int(1e9) + 7, int(1e9) + 9};
	vector<int> base = {int(2e5) + 3, int(2e5) + 16};
	vector<int> val = {rand() % base[0], rand() % base[0]};
	int H = mod.size();
	vector<vector<int>> h(H, vector<int>(n + 2, 0));
	for (int i = n; i >= 1; --i) {
		cnt[i] = cnt[i + 1] + (t[i] == '0');
		for (int j = 0; j < H; ++j) {
			if (t[i] == '0') {
				h[j][i] = add(val[0], mul(base[j], h[j][i + 1], mod[j]), mod[j]);
			} else {
				h[j][i] = sub(val[1], h[j][i + 1], mod[j]);
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		bool ok = true;
		for (int j = 0; j < H; ++j) {
			int h1 = get_hash(h[j], base[j], mod[j], cnt, l1, l1 + len - 1);
			int h2 = get_hash(h[j], base[j], mod[j], cnt, l2, l2 + len - 1);
			ok &= (h1 == h2);
		}
		if (ok) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}

int get_hash(vector<int>& h, int base, int mod, vector<int>& cnt, int l, int r) {
	int a = pwr(base, cnt[l] - cnt[r + 1], mod);
	if (((r - l + 1) - (cnt[l] - cnt[r + 1])) % 2 == 1) {
		a = sub(0, a, mod);
	}
	int ans = sub(h[l], mul(a, h[r + 1], mod), mod);
	return ans;
}