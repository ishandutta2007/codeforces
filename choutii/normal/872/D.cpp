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

const int MaxN = 10123;
int n;
int bp[MaxN], pb[MaxN], bb[MaxN], pp[MaxN];
int p[MaxN], b[MaxN];

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("? %d %d\n", i, 0);
		fflush(stdout);
		scanf("%d", pb + i);  // p[i] ^ b[0]
	}
	
	for(i = 0; i < n; i++) {
		printf("? %d %d\n", 0, i);
		fflush(stdout);
		scanf("%d", bp + i); // b[i] ^ p[0]
	}
	
	for(i = 0; i < n; i++) pp[i] = (bp[0] ^ pb[i]);
	for(i = 0; i < n; i++) bb[i] = (bp[0] ^ bp[i]);
	int b0, cnt = 0;
	for(b0 = 0; b0 < n; b0++) {
		b[0] = b0;
		for(i = 1; i < n; i++) b[i] = b0 ^ bb[i];
		
		p[0] = (b[0] ^ bp[0]);
		
		for(i = 1; i < n; i++) p[i] = p[0] ^ pp[i];
		
		int chk = 1;
		
		for(i = 0; i < n; i++)if(p[b[i]] != i) {
			chk = 0; break;
		}
		
		if(!chk) continue;
		
		sort(b, b + n);
		for(i = 0; i < n; i++) if(b[i] != i) {
			chk = 0; break;
		}
		if(!chk) continue;
		
		cnt += chk;
	}
	
	printf("!\n");
	printf("%d\n", cnt);
	for(b0 = 0; b0 < n; b0++) {
		b[0] = b0;
		for(i = 1; i < n; i++) b[i] = b0 ^ bb[i];
		
		p[0] = (b[0] ^ bp[0]);
		
		for(i = 1; i < n; i++) p[i] = p[0] ^ pp[i];
		
		int chk = 1;
		
		for(i = 0; i < n; i++)if(p[b[i]] != i) {
			chk = 0; break;
		}
		if(!chk) continue;
		
		sort(b, b + n);
		for(i = 0; i < n; i++) if(b[i] != i) {
			chk = 0; break;
		}
		
		if(!chk) continue;
		
		
		if(chk) {
			for(i = 0; i < n; i++) printf("%d ", p[i]); return 0;
		}
	}
	return 0;
}