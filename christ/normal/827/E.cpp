#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
const long long mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
long long modpow(long long b, long long e) {
	long long ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
void ntt(vector<long long> &a) {
	int n = (int)a.size(), L = 31 - __builtin_clz(n);
	static vector<long long> rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		long long z[] = {1, modpow(root, mod >> s)};
		for (int i = k; i < 2*k; i++) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vector<int> rev(n);
	for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) for (int j = 0; j < k; j++) {
			long long z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vector<long long> conv(const vector<long long> &a, const vector<long long> &b) {
	if (a.empty() || b.empty()) return {};
	int s = (int)a.size() + (int)b.size() - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vector<long long> L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	for (int i = 0; i < n; i++) out[-i & (n - 1)] = (long long)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}
char s[MN];
mt19937 rnd(69);
void solve () {
	int n; scanf ("%d",&n);
	scanf ("%s",s);
	vector<long long> p1(n), p2(n), got;
	auto get = [&] (char c1, char c2) {
		for (int i = 0; i < n; i++) {
			p1[i] = (rnd()%mod) * (s[i] == c1);
			p2[i] = (rnd()%mod) * (s[i] == c2);
		}
		reverse(p1.begin(),p1.end());
		got = conv(p1,p2);
		vector<bool> ret(n+1);
		for (int i = 0; i < n; i++) ret[i] = got[i+n-1] == 0;
		ret[n] = true;
		return ret;
	};
	vector<bool> vk = get('V','K'), kv = get('K','V'), ret(n+1);
	int tot = 0;
	for (int i = n; i >= 1; i--) {
		ret[i] = true;
		for (int j = i; j <= n; j += i) if (!vk[j] || !kv[j]) {
			ret[i] = false;
		}
		tot += ret[i];
	}
	printf ("%d\n",tot);
	for (int i = 1; i <= n; i++) if (ret[i]) printf ("%d ",i);
	printf ("\n");
	
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}