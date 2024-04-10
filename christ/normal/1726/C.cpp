#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5;
char s[MN];
int p[MN];
int find (int n) {return p[n] == n ? n : p[n] = find(p[n]);}
void merge (int a, int b) {p[find(a)] = find(b);}
void solve() {
	int n; scanf ("%d",&n); n *= 2;
	scanf ("%s",s+1);
	assert((int)strlen(s+1) == n);
	for (int i = 1; i <= n; i++) p[i] = i;
	vector<int> stk;
	vector<int> match(n+1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') stk.push_back(i);
		else {
			int j = stk.back(); stk.pop_back();
			match[j] = i;
		}
	}
	for (int i = 1; i<= n; i++) if (s[i] == '(') {
		merge(i,match[i]);
		if (match[i] < n && s[match[i] + 1] == '(') {
			merge(i,match[match[i] + 1]);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) if (find(i) == i) ++ret;
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}