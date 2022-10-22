#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;

using namespace std;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n;
		scanf ("%d", &n);
		vector <int> a(n);
		for (auto &it : a) scanf ("%d", &it);
		sort(a.begin(), a.end());
		if (a[0] == a.back()) printf ("%d\n", n);
		else printf ("1\n");
	}																			
	return 0;
}