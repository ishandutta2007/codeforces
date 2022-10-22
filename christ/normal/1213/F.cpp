#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 3e5+5;
char s[MN];
int main () {
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<int> p1(n+1), p2(n+1), pp(n+1), invp1(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&p1[i]), invp1[p1[i]] = i;
	for (int i = 1; i <= n; i++) scanf ("%d",&p2[i]), pp[i] = invp1[p2[i]];
	int mx = INT_MIN, mn = INT_MAX;
	vector<int> can;
	for (int i = n; i >= 2; i--) {
		mn = min(mn,pp[i]); mx = max(mx,pp[i]);
		if (mn == i && mx == n) {
			can.push_back(i);
		}
	}
	if (can.size() < k-1) return !printf ("NO\n");
	printf ("YES\n");
	while (can.size() > 25) can.pop_back();
	char cur = 'a';
	for (int i = 1; i <= n; i++) {
		if (!can.empty() && can.back() == i) {
			++cur;
			can.pop_back();
		}
		s[p1[i]] = cur;
	}
	printf ("%s\n",s+1);
	return 0;
}