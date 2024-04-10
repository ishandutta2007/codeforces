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

const int MaxN = 101234;

int n, m, K, rn, a[MaxN], f[MaxN], g[MaxN]; 
pair<int, int> r[MaxN];


struct team {
	LL len;
	vector<pair<int, int> >	x, y;
	#define R (y.size() - 1)
	void append(pair<int, int> pa) {
		if(y.size()) {
			if(y[R].fir == pa.fir)
				y[R].sec += pa.sec;
			else
				y.push_back(pa);
		} else 
			y.push_back(pa);
			
		len += pa.sec;
		while(y.size()) {
			len -= y[R].sec / K * K;
			if(y[R].sec %= K)
				break;
			else
				y.pop_back(); 
		}
	}
}res, A;

team mul(team a, team b) {
	int i, t = a.len, up = 2 * n;
	if(b.len <= up) 
		for(i = 0; i < b.y.size(); i++)
			a.append(b.y[i]);
	else {
		LL sum = 0;
		for(i = 0; i < b.x.size(); i++)
			a.append(b.x[i]), sum += b.x[i].sec;
		a.y = b.y;
		a.len = a.len + b.len - sum;
	}
	if(t <= up && a.len > up) a.x = a.y;
	return a;
}

void build_A() {
	int i;
	for(i = 1; i <= n; i++)
	if(a[i] != r[rn].fir)
		r[++rn] = make_pair(a[i], 1);
	else
		r[rn].sec++;
	for(i = 1; i <= rn; i++) A.append(r[i]);
}

int main() {
	int i;
	n = read(); K = read(); m = read();
	int all = 1;
	for(i = 1; i <= n; i++)	{
		a[i] = read();
		if(i > 1 && a[i] != a[i - 1])
			all = 0;
	} 
	
	if(all) return printf("%d\n", (LL) n * m % K), 0;
	
	build_A();
	for(; m; m >>= 1) {
		if(m & 1) 
			res = mul(res, A);
		A = mul(A, A);
	}
	
	printf("%lld\n", res.len);
	return 0;
}