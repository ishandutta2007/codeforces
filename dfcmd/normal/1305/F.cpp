#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
namespace fastIO{
#define getchar() my_getchar()
#define putchar(x) my_putchar(x)
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
	char buf[IN_BUF], *ps = buf, *pt = buf;
	inline char my_getchar() {
		return ps == pt && (pt = (ps = buf) + fread(buf, 1, IN_BUF, stdin), ps == pt) ? EOF : *ps++;
	}
	template<typename T> inline bool read(T &x){
		char op = 0, ch = getchar();
		for (x = 0; !isdigit(ch) && ch != EOF; ch = getchar()) if (ch == '-') op ^= 1;
		if (ch == EOF) return false;
		for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ '0');
		if (ch != '.') return op ? x = -x : 0, true; else ch = getchar();
		T t = 1;
		for (; isdigit(ch); ch = getchar()) t /= 10, x += (ch ^ '0') * t;
		return op ? x = -x : 0, true;
	}
	inline int reads(char *s){
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar()) ;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
		return s[n] = '\0', n;
	}
	char pbuf[OUT_BUF], *pp = pbuf;
	struct _flusher{ ~_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } OutputFlusher;
	inline void my_putchar(char x){
		pp == pbuf + OUT_BUF ? fwrite(pbuf, 1, OUT_BUF, stdout), pp = pbuf : 0, *pp++ = x;
	}
	template<typename T> inline void print_(T x){
		if (x == 0) return putchar('0'), void(0);
		std::vector<int> num;
		for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num.push_back(x % 10);
		while (!num.empty()) putchar(num.back() ^ '0'), num.pop_back();
	}
	template<typename T> inline void print(T x, char ch = '\n'){
		print_(x), putchar(ch);
	}
	inline void prints_(const char *s, int n = -1){
		if (n == -1) n = strlen(s);
		for (register int i = 0; i < n; ++i) putchar(s[i]);
	}
	inline void prints(const char *s, int n = -1, char ch = '\n'){
		prints_(s, n), putchar(ch);
	}
	template<typename T> inline void printd_(T x, int n){
		if (x < 0) x = -x, putchar('-');
		long long a, b;
		for (register int i = 0; i < n; ++i) x *= 10;
		x = (long long)(x + 0.5);
		for (register int i = 0; i < n; ++i) x /= 10;
		a = x, x -= a;
		for (register int i = 0; i < n; ++i) x *= 10;
		b = x;
		print_(a);
		if (n) putchar('.'); else return;
		std::vector<int> num(n);
		for (register int i = 0; i < n; ++i) num[i] = b % 10, b /= 10;
		while (!num.empty()) putchar(num.back() ^ '0'), num.pop_back();
	}
	template<typename T> inline void printd(T x, int n, char ch = '\n'){
		printd_(x, n), putchar(ch);
	}
}
using namespace fastIO;
namespace rand_number{
	unsigned long long seed = 0x3C9FC1DA24BB75DFull;
	void srnd(unsigned long long _sd){ seed ^ _sd ? seed ^= _sd : 0; }
	unsigned long long rnd(){
		seed ^= seed >> 12;
		seed ^= seed << 25;
		seed ^= seed >> 27;
		return seed * 0x2545F4914F6CDD1Dull;
	}
}
using namespace rand_number;
const int N = 200005;
int n;
long long a[N];
long long calc(long long x){
	long long s = 0;
	for (register int i = 1; i <= n; ++i)
		if (a[i] < x) s += x - a[i];
		else s += std::min(a[i] % x, x - a[i] % x);
	return s;
}
void solve(){
	srnd(time(0));
	read(n);
	for (register int i = 1; i <= n; ++i) read(a[i]);
	for (register int i = 1; i <= n; ++i) std::swap(a[i], a[rnd() % i + 1]);
	long long ans = n;
	for (register int _ = 1; _ <= 20; ++_){
		int p = rnd() % n + 1;
		for (register int d = -1; d <= 1; ++d){
			long long x = a[p] + d;
			if (x <= 1) continue;
			for (register int i = 2; 1ll * i * i <= x; ++i)
				if (x % i == 0){
					ans = std::min(ans, calc(i));
					while (x % i == 0) x /= i;
				}
			if (x > 1) ans = std::min(ans, calc(x));
		}
	}
	print(ans);
}
int main(){
	int T = 1;
	// read(T);
	while (T--) solve();
}