#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;

typedef long long LL;

template <typename T> inline bool cmin(T & a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool cmax(T & a, const T &b) { return a < b ? a = b, 1 : 0; }

int getint() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int M = 262144; //M>=n+10
const int MaxN = M << 1;

struct info { 
	int f[5][5]; 
	info(char c = 0) {
		int i, j;
		for(i = 0; i < 5; i++) for(j = 0; j < 5; j++) f[i][j] = i == j ? 0 : 1e9;
		char s[] = "2017";
	    int pos = find(s, s + 4, c) - s;
	    if(pos < 4) {
			f[pos][pos + 1] = 0;
	    	f[pos][pos] = 1;
	    }
	    if(c == '6') {
	    	f[3][3] = 1;
	    	f[4][4] = 1;
	    }
	}
	void print() {return;
		for(int i = 0; i < 5; i++, puts(""))
			for(int j = 0; j < 5; j++)
				printf("%d ", f[i][j]);
	}
};

info seg[MaxN]; 

info operator + (info l, info r) {
	info x;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++) {
			x.f[i][j] = 1e9;
			for(int k = 0; k < 5; k++)
				cmin(x.f[i][j], l.f[i][k] + r.f[k][j]);
		}
	return x;
}
 
int n, q, pre[MaxN], s[MaxN]; char a[MaxN];
info query(int l, int r) {
	info qL, qR;
	for(l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if(~l & 1) qL = qL + seg[l ^ 1];
		if(r & 1) qR = seg[r ^ 1] + qR;
	}
	return qL + qR;
}

int main(){
	int i;
	n = getint(); q = getint();
	scanf("%s", a + 1);
	for(i = 1; i <= n; i++) seg[i + M] = info(a[i]);
	for(i = M - 1; i; i--) seg[i] = seg[i + i] + seg[i + i + 1];
	
	while(q--) {
		int l = getint(), r = getint();
		info ans = query(l, r);
		if(ans.f[0][4] >= 1e9) 
			puts("-1");
		else 
			printf("%d\n", ans.f[0][4]);
	}
	return 0;
}