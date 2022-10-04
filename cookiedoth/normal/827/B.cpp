#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstring>
#define null NULL
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

int n, k;
vector<pair<int, int> > edge;

void add_tail(int &v, int len, int root) {
	edge.push_back({root, v});
	for (int i = v; i < v + len - 1; ++i) {
		edge.push_back({i, i+1});
	}
	v += len;
}

bool check(int d) {
//	cout << "CHECK " << d << endl;
	edge.clear();
	for (int i = 0; i < d; ++i) {
		edge.push_back({i+1, i+2});
	}
	int e = d / 2;
	int v = d + 2;
	int k1 = k - 2;
	int v1 = n - k - (d - 1);
//	cout << e << " " << v << " " << k1 << " " << v1 << endl;
	while (v1 > 0) {
		if (k1 == 0)
			return 0;
		if (v1 >= e-1) {
			add_tail(v, e, e + 1);
			v1 -= (e - 1);
			k1 -= 1;
		}
		else {
			add_tail(v, v1 + 1, e + 1);
			v1 = 0;
			k1 -= 1;
		}
	}
	while (k1 > 0) {
		add_tail(v, 1, e + 1);
		k1--;
	}
	return 1;
}

int binsearch(int l, int r) {
	if (l == r) {
        check(l);
        return l;
	}
	int m = (l + r) / 2;
	if (check(m)) return binsearch(l, m);
	else return binsearch(m+1, r);
}

int main() {
	cin >> n >> k;
	cout << binsearch(2, n - k + 1) << '\n';
	for (int i = 0; i < n - 1; ++i) {
		cout << edge[i].first << ' ' << edge[i].second << '\n';;
	}
	return 0;
}