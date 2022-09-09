#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3405;
const int Q = 1e9 + 7;
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
const int MAXP = 205, P = 1e9;
struct INT {
	int len, a[MAXP];
	INT () {
		len = 1;
		memset(a, 0, sizeof(a));
	}
	INT (int num) {
		assert(num < P);
		len = 1;
		memset(a, 0, sizeof(a));
		a[0] = num;
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
int p, q; INT n;
int tot, a[MAXN], dp[MAXN][2][2][MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= Q) x -= Q;
}
int func(int Max, int Lft) {
	if (Lft == 0) return (1ll + Max) * (2ll + Max) / 2 % Q;
	else return (1ll + Max) * (0ll + Max) / 2 % Q;
}
int gunc(int Max, int Lft) {
	if (Lft == 0) return (1ll + Max) * (p - 1 + p - 1 - Max) / 2 % Q; 
	else return (1ll + Max) * (p + p - Max) / 2 % Q;
}
int work(int pos, bool top, int last, int sum) {
	if (dp[pos][top][last][sum] != -1) return dp[pos][top][last][sum];
	int &ans = dp[pos][top][last][sum]; ans = 0;
	if (pos == 0) return ans = (last == 0) && (sum >= q);
	if (top) {
		if (last) {
			update(ans, 1ll * (p - 1 - a[pos]) * work(pos - 1, true, 0, sum) % Q);
			update(ans, 1ll * (p - 0 - a[pos]) * work(pos - 1, true, 1, sum + 1) % Q);
			update(ans, 1ll * gunc(a[pos] - 1, 0) * work(pos - 1, false, 0, sum) % Q);
			update(ans, 1ll * gunc(a[pos] - 1, 1) * work(pos - 1, false, 1, sum + 1) % Q);
		} else {
			update(ans, 1ll * (a[pos] + 1) * work(pos - 1, true, 0, sum) % Q);
			update(ans, 1ll * (a[pos] + 0) * work(pos - 1, true, 1, sum + 1) % Q);
			update(ans, 1ll * func(a[pos] - 1, 0) * work(pos - 1, false, 0, sum) % Q);
			update(ans, 1ll * func(a[pos] - 1, 1) * work(pos - 1, false, 1, sum + 1) % Q);
		}
	} else {
		if (last) {
			update(ans, 1ll * gunc(p - 1, 0) * work(pos - 1, false, 0, sum) % Q);
			update(ans, 1ll * gunc(p - 1, 1) * work(pos - 1, false, 1, sum + 1) % Q);
		} else {
			update(ans, 1ll * func(p - 1, 0) * work(pos - 1, false, 0, sum) % Q);
			update(ans, 1ll * func(p - 1, 1) * work(pos - 1, false, 1, sum + 1) % Q);
		}
	}
	return ans;
}
int main() {
	read(p), read(q), read(n);
	while (n > 0) {
		a[++tot] = n % p;
		n /= p;
	}
	memset(dp, -1, sizeof(dp));
	cout << work(tot, 1, 0, 0) << endl;
	return 0;
}