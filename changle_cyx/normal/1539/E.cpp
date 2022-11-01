#include <bits/stdc++.h>

using namespace std; 

typedef pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0';
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int MaxN = 100000 + 5; 

struct stk {
	int na, nb; 
	pii a[MaxN], b[MaxN];  

	void push(int i, int x, int y) {
		while (na && a[na].first <= x) --na; 
		a[++na] = make_pair(x, i); 
		while (nb && b[nb].first >= y) --nb; 
		b[++nb] = make_pair(y, i); 
	}

	int finda(int v) {
		int l = 1, r = na, mid, res = na + 1; 
		while (l <= r) {
			mid = (l + r) >> 1; 
			if (a[mid].first <= v)
				res = mid, r = mid - 1; 
			else
				l = mid + 1; 
		}
		return a[res - 1].second - 1; 
	}

	int findb(int v) {
		int l = 1, r = nb, mid, res = nb + 1; 
		while (l <= r) {
			mid = (l + r) >> 1; 
			if (b[mid].first >= v)
				res = mid, r = mid - 1; 
			else
				l = mid + 1; 
		}
		return b[res - 1].second - 1; 
	}

	int find(int v) {
		return min(finda(v), findb(v)); 
	}
}sa, sb; 

int n, m, v[MaxN];
int f[MaxN][2]; 

int sL[MaxN], sR[MaxN]; 
int a[MaxN][2], b[MaxN][2]; 

int main() {
	read(n), read(m); 
	for (int i = 1; i <= n; ++i) {
		read(v[i]), read(a[i][0]), read(a[i][1]), read(b[i][0]), read(b[i][1]); 

		sL[i] = sL[i - 1] + (v[i] >= a[i][0] && v[i] <= a[i][1]); 
		sR[i] = sR[i - 1] + (v[i] >= b[i][0] && v[i] <= b[i][1]); 
	}

	sa.push(n + 1, m + 1, -1); 
	sb.push(n + 1, m + 1, -1); 

	int j0 = 0, j1 = 0; 
	if (sL[n] != sL[n - 1]) f[n][0] = n + 1, j0 = n; 
	sa.push(n, a[n][0], a[n][1]); 
	
	if (sR[n] != sR[n - 1]) f[n][1] = n + 1, j1 = n; 
	sb.push(n, b[n][0], b[n][1]); 

	for (int i = n - 1; i >= 0; --i) {
		sa.push(i, a[i][0], a[i][1]); 
		sb.push(i, b[i][0], b[i][1]); 

		if (j1 && sR[j1] - sR[i] == j1 - i && sa.find(v[i]) >= j1) f[i][0] = j1; 
		if (j0 && sL[j0] - sL[i] == j0 - i && sb.find(v[i]) >= j0) f[i][1] = j0; 

		if (f[i][0]) j0 = i; 
		if (f[i][1]) j1 = i; 
	}

	if (f[0][0] || f[0][1]) {
	    //  1->2  0 
	    //  0
		puts("Yes"); 

		for (int x = 0, op = f[0][0] ? 0 : 1, y; x <= n; x = y, op ^= 1) {
			y = f[x][op]; 
			if (x) printf("%d ", op); 
			for (int i = x + 1; i < y; ++i) printf("%d ", op ^ 1); 
		}
	} else {
		puts("No"); 
	}

	return 0; 
}