#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 1000000+1;
const int BASE = 1000000000;

typedef vector<int> lnum;

lnum read() {
	char buf[MAXN];
	scanf (" %s", buf);
	int n = (int) strlen (buf);
	lnum res;
	for (int i=n-9; ; i-=9) {
		i = max (i, 0);
		res.push_back (atoi (buf+i));
		buf[i] = 0;
		if (i == 0)
			break;
	}
	return res;
}

void dec (lnum & a) {
	for (int i=0; ; ++i) {
		--a[i];
		if (a[i] >= 0)
			break;
		a[i] += BASE;
	}
	while (a.size() && !a.back()) a.pop_back();
}

int mod (lnum a, int b) {
	int carry = 0;
	for (int i=(int)a.size()-1; i>=0; --i) {
		long long cur = carry * 1ll * BASE + a[i];
		carry = int (cur % b);
	}
	return carry;
}

int phi (int n) {
	int res = 1;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			int pw = 1;
			while (n % i == 0) {
				n /= i;
				pw *= i;
			}
			res *= pw - pw / i;
		}
	if (n > 1)
		res *= n - 1;
	return res;
}

int powmod (int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1)
			res = res * 1ll * a % p,  --b;
		else
			a = a * 1ll * a % p,  b >>= 1;
	return res;
}

int powmod (lnum a, lnum b, int p) {
	int aa = mod (a, p);
	int ph = phi(p);
	int bb = mod (b, ph);

	int res = powmod (aa, bb, p);
	
	if (b.size() > 1 || b.size() && b[0] >= ph)
		res = res * 1ll * powmod (aa, ph, p) % p;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	lnum a = read(), b = read();
	int p;
	cin >> p;

	if (p == 1) {
		cout << 1;
		return 0;
	}

	int res1 = powmod (a, b, p);
	dec (b);
	int res2 = powmod (a, b, p);
	int res = res1-res2;
	if (res <= 0)
		res += p;
	cout << res;

}