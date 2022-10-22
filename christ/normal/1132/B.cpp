#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
int main () { 
	int n;
	scanf ("%d",&n);
	vector<int> a(n); ll sum = 0;
	for (auto &au : a) scanf ("%d",&au), sum += au;
	sort(all(a));
	int m;
	scanf ("%d",&m);
	while (m--) {
		int b; scanf ("%d",&b);
		printf ("%lld\n",sum-a[n-b]);
	}
	return 0;
}