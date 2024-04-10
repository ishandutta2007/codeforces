#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define allof(s) (s).begin(), (s).end()

template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

const int N = 200008;
int n;
int a[N];
int sorted[N];
map<int, int> inverter;

int ranks[N]; // 0 to n - 1

int greedy(int start) {
	int cur = ranks[start];
	int ret = 1;
	fori (i, start + 1, n) {
		if (ranks[i] == cur + 1) {
			ret++;
			cur++;
		}
	}
	return ret;
}

void tc() {
	inverter.clear();

	cin >> n;
	fori (i, 0, n) {
		cin >> a[i];
		sorted[i] = a[i];
	}

	sort(sorted, sorted + n);

	fori (i, 0, n) {
		inverter[sorted[i]] = i;
	}

	fori (i, 0, n) {
		ranks[i] = inverter[a[i]];
	}

	int leavable = 0;
	fori (i, 0, n) {
		leavable = max(leavable, greedy(i));
	}

	cout << (n - leavable) << "\n";
}

int main() {
	int tcn;
	cin >> tcn;
	fori (i, 0, tcn) tc();
}