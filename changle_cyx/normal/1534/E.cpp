#include <bits/stdc++.h>

using namespace std; 

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x) {
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else {
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y) {
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

using std::cerr; 
using std::cout; 
typedef long long s64; 
typedef long double ld; 
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 500 + 5; 
const int INF = 0x3f3f3f3f; 

int n, K; 
pii f[MaxN]; 

bool vis[MaxN]; 

void DP(int p) {
	if (vis[p]) return; 
	vis[p] = true; 
	
	for (int i = p - K; i <= p + K; i += 2)
		if (i != p && i >= 0 && i <= n && i + (p - i + K) / 2 <= n && (i - p + K) / 2 <= i) {
			DP(i); 
			tense(f[p], pii(f[i].first + 1, i)); 
		}
}

int res = 0; 

int main() {
	read(n), read(K); 
	fill(f, f + n + 1, pii(INF, 0)); 

	f[K] = {1, 0}; 
	vis[K] = true; 

	if (DP(n), f[n].first < INF) {
		static int used[MaxN];  
		vector<int> pos; 

		int x = n; 
		while (x) {
			pos.push_back(x); 
			x = f[x].second; 
		}

		pos.push_back(0); 

		for (int i = pos.size() - 1; i > 0; --i) {
			vector<bool> ban(n + 2); 
			int p = pos[i], q = pos[i - 1]; 

			// cerr << ": " << p << ' ' << q << '\n'; //

			printf("? "); 
			int cur = 0; 
			while (p < q) {
				for (int x = 1; x <= n; ++x)
					if (!used[x]) {
						printf("%d ", x); 
						used[x] ^= 1; 
						ban[x] = 1; 
						break; 
					}
				++p; 
				++cur; 
			}
			while (p > q) {
				for (int x = 1; x <= n; ++x)
					if (used[x] && !ban[x]) {
						printf("%d ", x); 
						used[x] ^= 1; 
						ban[x] = 1; 
						break; 
					}
				--p; 
				++cur; 
			}

			while (cur < K) {
				for (int x = 1; x <= n; ++x)
					if (!used[x] && !ban[x]) {
						printf("%d ", x); 
						used[x] ^= 1; 
						ban[x] = 1; 
						break; 
					}
				for (int x = 1; x <= n; ++x)
					if (used[x] && !ban[x]) {
						printf("%d ", x); 
						used[x] ^= 1; 
						ban[x] = 1; 
						break; 
					}
				cur += 2; 
			}
			
			putchar('\n'); 
			fflush(stdout); 

			assert(cur == K); 

			int val; 
			scanf("%d", &val); 
			res ^= val; 
		}

		printf("! %d\n", res); 
		fflush(stdout); 
	} else {
		puts("-1"); 
	}

	return 0; 
}