#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	if (k > n || k < __builtin_popcount(n)) return !printf ("NO\n");
	multiset<int> bits;
	for (int i = 0; i <= 30; i++) if (n>>i&1) bits.insert(1 << i);
	while (bits.size() < k) {
		int aaa = *prev(bits.end());
		bits.erase(prev(bits.end()));
		bits.insert(aaa/2); bits.insert(aaa/2);
	}
	printf ("YES\n");
	for (int i : bits) printf ("%d ",i);
	printf ("\n");
    return 0;
}