#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<int> s, ss;
	int n, m;
	static int a[100010], b[100010], c[100010];
	scanf("%d%d", &n, &m);
	bool f1 = false, f2 = false;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(s.count(a[i])) ss.insert(a[i]);
		s.insert(a[i]);
		c[a[i]] = i + 1;
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		if(!s.count(b[i])) f2 = true;
		if(ss.count(b[i])) f1 = true;
	}
	if(f2) {
		puts("Impossible");
		return 0;
	}
	else if(f1) {
		puts("Ambiguity");
	}
	else {
		puts("Possible");
		for(int i = 0; i < m; ++i)
			printf("%d%c", c[b[i]], " \n"[i + 1 == m]);
	}
	return 0;
}