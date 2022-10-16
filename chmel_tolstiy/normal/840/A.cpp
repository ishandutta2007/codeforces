#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
	int n; cin >> n;
	vector<pii> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first; a[i].second = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[b[i].second] = a[n - 1 - i].first;
	}

	for (int i = 0; i < n; ++i) cout << c[i] << ' ';

    return false;
}

int main() {

    while (solve());
    
    return 0;
}