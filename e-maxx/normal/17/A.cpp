#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, k;
	cin >> n >> k;

	vector<char> pr (n+1);
	for (int i=2; i<=n; ++i) {
		pr[i] = true;
		for (int j=2; j*j<=i; ++j)
			if (i % j == 0)
				pr[i] = false;
	}

	vector<int> next (n+1);
	for (int j=0; j<=n; ++j)
		if (pr[j])
			for (int k=j+1; k<=n; ++k)
				if (pr[k]) {
					next[j] = k;
					break;
				}

	int cnt = 0;
	for (int i=2; i<=n; ++i)
		if (pr[i])
			for (int k=0; k<=i; ++k)
				if (pr[k] && i-1-k>=0 && pr[i-1-k] && next[k] == i-1-k) {
					++cnt;
					break;
				}
	puts (cnt>=k ? "YES" : "NO");

}