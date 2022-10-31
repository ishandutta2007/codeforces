#include <iostream>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

int t;

long long delta(long long a0) {
	long long mind = 1000, maxd = -1000;
	long long a = a0;
	while (a) {
		minify(mind, a % 10);
		maxify(maxd, a % 10);
		a /= 10;
	}
	return mind * maxd;
}

int main() {
	cin >> t;
	fori (i, 0, t) {
		long long a, k;
		cin >> a >> k;

		for (long long x = 0; x < k - 1; x++) {
			long long d = delta(a);
			if (d == 0) break;
			a += d;
		}

		cout << a << "\n";
	}
}