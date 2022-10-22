#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e6+2, MOD = 1e9+7, LOG = 15, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
void solve () {
	int n;
	scanf ("%d",&n);
	int cnt = 0; set<int> st;
	for (int i = 2; i * i <= n; i++) if (n%i==0 && cnt < 2) {
		cnt++;
		n /= i;
		st.insert(i);
	}
	if (n != 1 && !st.count(n) && cnt == 2) printf ("YES\n%d %d %d\n",*st.begin(),*(++st.begin()),n);
	else printf ("NO\n");
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}