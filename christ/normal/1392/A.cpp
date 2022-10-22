#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5 + 5, MOD = 1e9 + 7;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	set<int> st;
	for (auto &au : a) scanf ("%d",&au), st.insert(au);
	if (st.size() == 1) printf ("%d\n",n);
	else printf ("1\n");
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}