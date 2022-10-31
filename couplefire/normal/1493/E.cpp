#include <bits/stdc++.h>
using namespace std;

#define sz(a) int(a.size())
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int MOD = 1e9+7;

char cs[1'000'010];
int main() {
	int n;
	scanf("%d", &n);

	scanf("%s", cs);
	string l = cs;

	scanf("%s", cs);
	string r = cs;

	auto getNext = [&n] (string x) {
		int p = n-1;
		while (x[p] == '1') {
			x[p] = '0';
			p--;
		}
		x[p] = '1';
		return x;
	};

	string ans;
	if (l == r) {
		ans = r;
	} else if (l[0] != r[0]) {
		ans = string(n, '1');
	} else {
		ans = r;
		if (getNext(l) != r && r[n-1] == '0') ans[n-1] = '1';
	}
	puts(ans.c_str());
}