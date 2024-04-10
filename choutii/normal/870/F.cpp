#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 10001234;

int n; int p[MaxN], np[MaxN], mp[MaxN], phi[MaxN], mu[MaxN], d[MaxN], pn, bad;

LL ans, s[MaxN];

inline bool cbad(int x) {
	return x == 1 || (x > n / 2 && !np[x]);
}

LL one() {
	LL ans = 0;
	for(int i = 2; i <= n; i++) ans += i - 1 - phi[i];
	return ans;
}

LL two() {
	LL ans = 0; int i, j, pc = 1;
	for(i = 2; i <= n; i++) {
		if(np[i]) {
			ans += phi[i] - pc + d[i];
		}else {
			++pc;
		}
	}
	for(i = 1; i <= n; i++) s[mp[i]] += !cbad(i);
	for(i = 1; i <= n; i++) s[i] += s[i - 1];
	for(i = 2; i <= n; i++) {
		if(np[i] || cbad(i)) continue;
		ans += s[n / i];
		for(j = i; j <= n; j += i) 
			if(mp[j] <= n / i)
				--ans; 
	}
	for(i = 2; i <= n; i++) {
		if(np[i] && mp[i / mp[i]] == i / mp[i] && mp[i] != i / mp[i]) --ans;
	}
	
	return ans;
}

int main() {
	int i, j, pc = 0;
	cin >> n;
	
	mu[1] = 1;
	for(i = 2; i <= n; i++) {
		if(!np[i]) {
			p[++pn] = i;
			mp[i] = i;
			mu[i] = -1;
			phi[i] = i - 1;
		}
		
		for(j = 1; j <= pn && i * p[j] <= n; j++) {
			mp[i * p[j]] = p[j]; np[i * p[j]] = 1;
			
			if(i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j]; 
				mu[i * p[j]] = -mu[i];
				break;
			} else {
				phi[i * p[j]] = phi[i] * (p[j] - 1);
				mu[i * p[j]] = 0;
			}
		}
	}	
	for(i = 2; i <= n; i++)
		if(!np[i])
			d[i] = 1;
		else 
			d[i] = d[i / mp[i]] + (mp[i] != mp[i / mp[i]]);
	
	LL ans1 = one(); 
	LL ans2 = two();
	for(i = 1; i <= n; i++) bad += cbad(i);
	LL ans3 = (LL) (n - bad) * (n - bad - 1) / 2 - ans1 - ans2;
	cout << ans1 + ans2 * 2 + ans3 * 3;
	return 0;
}