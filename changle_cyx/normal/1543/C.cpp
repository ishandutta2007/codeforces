#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 
typedef pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt) x = ~x + 1; 
}

const int MaxN = 100 + 5; 

int n; 
double c, m, p, v; 
map<pii, double> f; 

double calc(double tp) {
	double res = 0, cur = 1; 
	while (tp > 0) {
		cur = cur * tp;  
		res += cur; 
		tp -= v; 
	}
	return res; 
}

double DP(int i, int j) {
	if (f.find({i, j}) != f.end()) return f[{i, j}]; 
	
	double &res = f[{i, j}]; 
	double p1 = c + i * v / 2, p2 = m + j * v / 2; 

	double f1 = 0, f2 = 0; 

	if (p1 <= v + 1e-10) {
		f1 = calc(p2 + p1 / 2) + 1; 
	} else {
		f1 = DP(i - 2, j + 1) + 1; 
	}

	if (p2 <= v + 1e-10) {
		f2 = calc(p1 + p2 / 2) + 1; 
	} else {
		f2 = DP(i + 1, j - 2) + 1; 
	}

	res = f1 * p1 + f2 * p2; 

	return res; 
}

void work() {
	cin >> c >> m >> p >> v; 

	f.clear(); 
	printf("%.8f\n", DP(0, 0) + 1); 
}

int main() {
	int T; 
	read(T); 

	while (T--) work(); 

	return 0; 
}