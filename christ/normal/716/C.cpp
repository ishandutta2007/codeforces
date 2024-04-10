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
const int MN = 2e5+4, MAXV = 1e4+5;
int main () { 
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		if (i == 1) printf ("2\n");
		else printf ("%lld\n",i * 1LL * (i+1) * 1LL * (i+1) - i + 1);
	}
	return 0;
}