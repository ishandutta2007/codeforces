#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
int main () {
	int n; ll ans = 0; priority_queue<int> change;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		int v; scanf ("%d",&v); v -= i;
		change.push(v); change.push(v);
		ans += change.top()-v;
		change.pop();
	}
	printf ("%lld\n",ans);
	return 0;
}