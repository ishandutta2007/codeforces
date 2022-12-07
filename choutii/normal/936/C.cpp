#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 2333;

char s[MaxN], t[MaxN]; int n;

int main() {
	n = read();
	scanf("%s%s", s + 1, t + 1);
	vector <int> ans;
	for (int i = 1, j; i <= n; i++) {
		for (j = n - i + 1; j; j--) if(s[j] == t[i]) break;
		if(!j) return puts("-1"), 0;
		ans.pb(n - j); ans.pb(1); ans.pb(n - 1);
		reverse(s + 1, s + j);
		for (int i = j; i < n; i++)
			swap(s[i], s[i + 1]);
	}
	printf("%d\n", SZ(ans));
	for (auto x : ans) printf("%d ", x);
	return 0;
}