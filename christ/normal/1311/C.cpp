#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
char s[MN];
void solve () {
	int n,m;
	scanf ("%d %d\n%s",&n,&m,s+1);
	vector<int> go(n+1); go[n] = 1;
	while (m--) {
		int a;
		scanf ("%d",&a);
		++go[a];
	}
	vector<int> ret(26);
	for (int i = n; i >= 1; i--) {
		if (i < n) go[i] += go[i+1];
		ret[s[i]-'a'] += go[i];
	}
	for (int i = 0; i < 26; i++) printf ("%d%c",ret[i]," \n"[i==25]);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}