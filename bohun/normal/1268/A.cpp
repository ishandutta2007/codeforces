#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int n, k;
char s[200005];
int a[200005];
int g[200005];

bool go() {
	for(int i = 0; i < n; ++i) {
		if(a[i] < g[i]) return 1;
		if(a[i] > g[i]) return 0;
	}
	return 1;
}

int main () {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for(int i = 0; i < n; ++i)
		a[i] = s[i] - '0';
	for(int i = 0; i < k; ++i)
		g[i] = a[i];
	for(int i = 0; i < n; ++i)
		g[i] = g[i % k];
	if(go()) {
		printf("%d\n", n);
		for(int i = 0; i < n; ++i)
			printf("%d", g[i]);
		exit(0);
	}
	for(int i = k - 1; 0 <= i; --i) {
		if(g[i] < 9) {
			g[i]++;
			for(int j = i + 1; j < k; ++j)
				g[j] = 0;
			break;
		}
	}
	for(int i = 0; i < n; ++i)
		g[i] = g[i % k];
	if(go()) {
		printf("%d\n", n);
		for(int i = 0; i < n; ++i)
			printf("%d", g[i]);
		exit(0);
	}



	return 0;
}