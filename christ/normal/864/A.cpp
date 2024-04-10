#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, BASE = 31; const ll MOD = 1000000000000037LL;
#define all(x) (x).begin(),(x).end()
int main() {
	int n;
	scanf ("%d",&n);
	map<int,int> freq;
	for (int i = 0; i < n; i++) {
		int a; scanf ("%d",&a); ++freq[a];
	}
	if (n&1 || freq.size() != 2 || freq.begin()->second != n/2) return !printf ("NO\n");
	return !printf ("YES\n%d %d\n",freq.begin()->first,(++freq.begin())->first);
}