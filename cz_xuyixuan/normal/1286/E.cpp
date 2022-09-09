#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
const int MAXP = 5, P = 1e9;
struct INT {
	int len, a[MAXP];
	INT () {
		len = 1;
		memset(a, 0, sizeof(a));
	}
	INT (ll num) {
		assert(num < 1ll * P * P);
		if (num < P) {
			len = 1;
			memset(a, 0, sizeof(a));
			a[0] = num;
		} else {
			len = 2;
			memset(a, 0, sizeof(a));
			a[0] = num % P;
			a[1] = num / P;
		}
	}
};
bool operator < (const INT &x, const INT &y) {
	if (x.len < y.len) return true;
	if (x.len > y.len) return false;
	for (int i = x.len - 1; i >= 0; i--) {
		if (x.a[i] < y.a[i]) return true;
		if (x.a[i] > y.a[i]) return false;
	}
	return false;
}
bool operator > (const INT &x, const INT &y) {
	if (x.len > y.len) return true;
	if (x.len < y.len) return false;
	for (int i = x.len - 1; i >= 0; i--) {
		if (x.a[i] > y.a[i]) return true;
		if (x.a[i] < y.a[i]) return false;
	}
	return false;
}
bool operator <= (const INT &x, const INT &y) {
	if (x.len < y.len) return true;
	if (x.len > y.len) return false;
	for (int i = x.len - 1; i >= 0; i--) {
		if (x.a[i] < y.a[i]) return true;
		if (x.a[i] > y.a[i]) return false;
	}
	return true;
}
bool operator >= (const INT &x, const INT &y) {
	if (x.len > y.len) return true;
	if (x.len < y.len) return false;
	for (int i = x.len - 1; i >= 0; i--) {
		if (x.a[i] > y.a[i]) return true;
		if (x.a[i] < y.a[i]) return false;
	}
	return true;
}
bool operator == (const INT &x, const INT &y) {
	if (x.len != y.len) return false;
	for (int i = x.len - 1; i >= 0; i--)
		if (x.a[i] != y.a[i]) return false;
	return true;
}
bool operator != (const INT &x, const INT &y) {
	if (x.len != y.len) return true;
	for (int i = x.len - 1; i >= 0; i--)
		if (x.a[i] != y.a[i]) return true;
	return false;
}
INT operator + (const INT &x, const INT &y) {
	INT res;
	res.len = max(x.len, y.len) + 1;
	for (int i = 0; i < res.len; i++) {
		res.a[i] += x.a[i] + y.a[i];
		if (res.a[i] >= P) {
			res.a[i + 1] += res.a[i] / P;
			res.a[i] %= P;
		}
	}
	while (res.len >= 2 && res.a[res.len - 1] == 0) res.len--;
	return res;
}
INT operator += (INT &x, const INT &y) {
	x = x + y;
	return x;
}
INT operator - (const INT &x, const INT &y) {
	INT res; assert(x >= y);
	res.len = x.len;
	for (int i = 0; i < res.len; i++) {
		res.a[i] += x.a[i] - y.a[i];
		if (res.a[i] < 0) {
			res.a[i + 1] += res.a[i] / P;
			res.a[i] %= P;
			if (res.a[i] < 0) {
				res.a[i + 1] -= 1;
				res.a[i] += P;
			}
		}
	}
	while (res.len >= 2 && res.a[res.len - 1] == 0) res.len--;
	return res;
}
INT operator -= (INT &x, const INT &y) {
	x = x - y;
	return x;
}
INT operator * (const INT &x, const INT &y) {
	INT res;
	res.len = x.len + y.len;
	static long long tres[MAXP];
	memset(tres, 0, sizeof(tres));
	for (int i = 0; i < x.len; i++)
	for (int j = 0; j < y.len; j++) {
		long long tmp = 1ll * x.a[i] * y.a[j];
		tres[i + j] += tmp % P;
		tres[i + j + 1] += tmp / P;
	}
	for (int i = 0; i < res.len; i++) {
		tres[i + 1] += tres[i] / P; 
		res.a[i] = tres[i] % P;
	}
	while (res.len >= 2 && res.a[res.len - 1] == 0) res.len--;
	return res;
}
INT operator *= (INT &x, const INT &y) {
	x = x * y;
	return x;
}
INT operator / (const INT &x, const int &y) {
	INT res; ll rem = 0;
	res.len = x.len;
	for (int i = x.len - 1; i >= 0; i--) {
		rem += x.a[i];
		res.a[i] = rem / y;
		rem = rem % y * P;
	}
	while (res.len >= 2 && res.a[res.len - 1] == 0) res.len--;
	return res;
}
INT operator /= (INT &x, const int &y) {
	x = x / y;
	return x;
}
int operator % (const INT &x, const int &y) {
	int ans = x.a[x.len - 1] % y;
	for (int i = x.len - 2; i >= 0; i--)
		ans = (1ll * P * ans + x.a[i]) % y;
	return ans;
}
INT operator %= (INT &x, const int &y) {
	x = x % y;
	return x;
}
void print(const INT &x) {
	printf("%d", x.a[x.len - 1]);
	for (int i = x.len - 2; i >= 0; i--)
		printf("%09d", x.a[i]);
	printf("\n");
}
struct Structure {
	ll ans; map <int, int> a;
	void inc(int pos) {
		a[pos] += 1;
		ans += pos;
	}
	void dec(int pos) {
		a[pos] -= 1;
		ans -= pos;
	}
	void chkmin(int val) {
		auto tmp = a.upper_bound(val);
		while (tmp != a.end()) {
			a[val] += (*tmp).second;
			ans -= 1ll * (*tmp).second * ((*tmp).first - val);
			a.erase(tmp), tmp = a.upper_bound(val);
		}
	}
} S;
namespace rmq {
	const int MAXN = 6e5 + 5;
	const int MAXLOG = 20;
	int Min[MAXN][MAXLOG], Log[MAXN];
	int queryMin(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return min(Min[l][tmp], Min[r - (1 << tmp) + 1][tmp]);
	}
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			Log[i] = Log[i - 1];
			if ((1 << (Log[i] + 1)) <= i) Log[i]++;
		}
	}
	void update(int pos, int val) {
		Min[pos][0] = val;
		for (int i = 1; (1 << i) <= pos; i++) {
			int res = pos - (1 << i) + 1;
			Min[res][i] = min(Min[res][i - 1], Min[res + (1 << (i - 1))][i - 1]);
		}
	}
}
char s[MAXN];
int n, nxt[MAXN], dif[MAXN], a[MAXN];
int main() {
	read(n); rmq :: init(n);
	int decode = 1 << 30; INT ans = 0;
	for (int i = 1; i <= n; i++) {
		char c; int w;
		scanf("\n%c%d", &c, &w);
		s[i] = (c - 'a' + ans % 26) % 26 + 'a';
		a[i] = w ^ (ans % decode);
		
		rmq :: update(i, a[i]);
		if (i != 1) dif[i - 1] = (s[i] == s[nxt[i - 1] + 1]) ? dif[nxt[i - 1]] : nxt[i - 1];
		
		if (s[i] == s[1]) S.inc(a[i]);
		S.chkmin(a[i]); int pos = i - 1;
		while (pos != 0) {
			if (s[pos + 1] == s[i]) pos = dif[pos];
			else S.dec(rmq :: queryMin(i - pos, i)), pos = nxt[pos];
		}
		ans += S.ans; print(ans);
	
		if (i != 1) {
			int res = nxt[i - 1];
			while (res != 0 && s[res + 1] != s[i]) res = nxt[res];
			if (s[res + 1] == s[i]) res++; nxt[i] = res;
		}
	}
	return 0;
}