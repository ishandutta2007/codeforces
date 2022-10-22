#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char s[MN];
void solve() {
	scanf ("%s",s);
	int n = strlen(s);
	if (s[0] == '?') s[0] = s[1] == 'a' ? 'b' : 'a';
	for (int i = 1; i < n; i++) {
		if (s[i] == '?') {
			for (char c = 'a'; c <= 'c'; c++) if (s[i-1] != c && s[i+1] != c) s[i] = c;
		}
		if (s[i] == s[i-1]) return (void) printf ("-1\n");
	}
	printf ("%s\n",s);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}