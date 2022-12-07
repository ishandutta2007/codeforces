#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return b > a ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 777;
const int up = 1e8;

struct bint {
    LL a[40];
    bint(){
		memset(a, 0, sizeof(a));
		a[0]=1;
	}
	bint(int x) {
		memset(a, 0, sizeof(a));
		a[0] = 1; a[1] = x;
	}
	LL & operator[] (const int x) {
		return a[x];
	}
	
	bint operator * (bint b) {
		bint c;
		for(int i = 1; i <= a[0]; i++)
			for(int j = 1; j <= b[0]; j++) {
				c[i + j - 1] += a[i] * b[j];
				if(c[i + j - 1] > up)
					c[i + j] += c[i + j - 1] / up, c[i + j - 1] %= up;
			}
		c[0] = min(a[0] + b[0], 40ll);
		while(!c[c[0]] && c[0] > 1) 
			c[0]--;
		return c;
	}
	
	bool operator > (bint b) const {
		if(a[0] != b[0]) return a[0] > b[0];
		for(int i = a[0]; i; i--)
			if(a[i] != b[i])
				return a[i] > b[i];
		return 0;
	}
    void print(){
        printf("%I64d", a[a[0]]);
        for (int i = a[0] - 1; i; i--){
            printf("%.8I64d", a[i]);
        }
    }
}f[MaxN][MaxN];

struct edge {
	int to, nxt;
}e[MaxN << 1]; int cnt, lst[MaxN], siz[MaxN];

int n;

void ins(int a, int b) {
	e[++cnt] = (edge) {b, lst[a]}; lst[a] = cnt;
}

void lnk(int a, int b) {
	ins(a, b);
	ins(b, a);
}

void dfs(int x, int fa = 0) {
  	siz[x] = 1;
	f[x][1] = 1;
	for(int i = lst[x], b; b = e[i].to, i; i = e[i].nxt) {
		if(b == fa) continue;
		dfs(b, x);
		for(int j = siz[x]; j; j--)
			for(int k = siz[b]; ~k; k--)
				cmax(f[x][j + k], f[x][j] * f[b][k]); 
		siz[x] += siz[b];
	} 
	f[x][0] = siz[x];
	for(int j = 1; j <= siz[x]; j++)
		cmax(f[x][0], f[x][j] * bint(j));
}

int main() {
	int i, j;
	n = read();
	for(i = 1; i < n; i++) {
		int u = read(), v = read();
		lnk(u, v);
	}
	dfs(1);
	
	f[1][0].print();
	return 0;
}