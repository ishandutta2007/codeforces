#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 100005;
vector<int> e[maxn], v;
int n, a, b, s;

int main() {
	scanf("%d", &n);
	rep (i, 2, n) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	s = 1;
	rep (i, 1, n)
		if (e[i].size() > e[s].size()) s = i;

	rep (i, 1, n)
		if (i != s && e[i].size() >= 3)
			return puts("No"), 0;
		else if (e[i].size() == 1)
			v.push_back(i);
	puts("Yes");
	printf("%d\n", (v.size() + 1) / 2);
	int k=0;
	while (k+1 < v.size()) {
		printf("%d %d\n", v[k], v[k+1]);
		k += 2;
	}
	if (v.size()&1) printf("%d %d\n", v.back(), s);
	
	return 0;
}