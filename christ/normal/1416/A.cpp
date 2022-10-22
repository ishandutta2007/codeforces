#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define all(x) (x).begin(),(x).end()
const int MN = 3e5 + 5;
void solve () {
	int n;
	scanf ("%d",&n);
	vector<int> a(n+1), lst(n+1), big(n+1);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		big[a[i]] = max(big[a[i]],i - lst[a[i]] - 1);
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		big[i] = max(big[i],n-lst[i]);
	}
	vector<int> ret(n+1); int ans = 1;
	for (int i = n; i >= 1; i--) {
		while (ans <= n && big[ans] >= i) ++ans;
		ret[i] = ans == n + 1 ? -1 : ans;
	}
	for (int i = 1; i <= n; i++) printf ("%d%c",ret[i]," \n"[i==n]);
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
	return 0;
}