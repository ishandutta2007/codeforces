#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

#define gc getchar
template<class T> void read(T &x) {
	char c = ' '; x = 0; int f = 1;
	while((c < '0' || c > '9') && c != '-') c = gc();
	if(c == '-') f = -1, c = gc();
	for(; c >= '0' && c <= '9'; c = gc()) x = x * 10 + c - '0';
}

int T, p1, p2, k;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

#define pc putchar
void write(int t) {
	if(t == 1) {
		pp("OBEY\n");
	} else {
		pp("REBEL\n");
	}
}
int main() {
	scanf("%d", &T);
	fo(ii, 1, T) {
		read(p1); read(p2); read(k);
		if(k == 1) {
			write(0);
			continue;
		}
		if(p1 == p2) {
			write(1);
			continue;
		}
		if(p1 > p2) swap(p1, p2);
		int d = gcd(p1, p2);
		p1 /= d, p2 /= d;
		int mx = p2 / p1 - (p2 % p1 == 0);
		mx = max(mx, (p2 - 1) / p1 + 1 - ((p2 - 1) % p1 == 0));
		write(mx >= k ? 0 : 1);
	}
}