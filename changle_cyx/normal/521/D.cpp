#include <bits/stdc++.h>

using namespace std; 

template <class T> inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

typedef long long s64; 
typedef pair<int, int> pii; 

template <class T> inline bool relax(T &x, const T &y) {
	return x < y ? x = y, true : false; 
}
//orzczk
const int MaxN = 100000 + 5; 

int n, K, m, a[MaxN]; 
int type[MaxN]; 

pii passign[MaxN]; 
vector<pii> padd[MaxN]; 
vector<pair<double, int> > alladd; 

int main() {
	read(n), read(K), read(m); 
	for (int i = 1; i <= n; ++i) read(a[i]); 
	for (int i = 1; i <= K; ++i) {
		int p, b; 
		read(type[i]), read(p), read(b); 
		
		if (type[i] == 3) {
			alladd.emplace_back(logl(b), i); 
		} else if (type[i] == 2) {
			padd[p].emplace_back(b, i); 
		} else {
			relax(passign[p], {b, i}); 
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (passign[i].second && passign[i].first > a[i])
			padd[i].emplace_back(passign[i].first - a[i], passign[i].second); 
		
		sort(padd[i].begin(), padd[i].end(), greater<pii>()); 

		s64 cur = a[i]; 
		for (pii p : padd[i]) {
			alladd.emplace_back(logl(cur + p.first) - logl(cur), p.second); 
			cur += p.first; 
		}
	}

	sort(alladd.begin(), alladd.end(), greater<pair<double, int> >()); 
	
	int s = min(m, (int)alladd.size()); 

	sort(alladd.begin(), alladd.begin() + s, [=](pair<double, int> x, pair<double, int> y) {
		if (type[x.second] != type[y.second]) return type[x.second] < type[y.second]; 
		else return x.first > y.first; 
	}); 


	printf("%d\n", s); 

	for (int i = 0; i < s; ++i) printf("%d%c", alladd[i].second, " \n"[i == s - 1]); 
	
	return 0; 
}