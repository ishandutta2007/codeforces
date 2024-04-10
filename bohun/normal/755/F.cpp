#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int nax = 1000001;

bitset <nax> bit;

int n, k;
int p[nax];
int dl = 0;
int odw[nax];
int ile[nax];
int t[2];

void dfs(int u) {
	dl += 1;
	odw[u] = 1;
	if(!odw[p[u]])
		dfs(p[u]);
}

int main() {
	scanf("%d %d", &n, &k);
	FOR(i, n) scanf("%d", p + i);
	FOR(i, n) 
		if(!odw[i]) {
			dl = 0;
			dfs(i);
			ile[dl] += 1;
			t[0] += dl / 2;
			t[1] += dl % 2;
		}
	bit.reset();
	bit[0] = 1;
	FOR(i, 1000000) {
		if(!ile[i])
			continue;
		int b = 32 - __builtin_clz(ile[i]) - 1;
		int x = (1 << b) - 1;
		for(int j = 0; j < b; ++j)
			bit |= (bit << ((1 << j) * i));
		for(int j = 0; j < 20; ++j)
			if((((ile[i] - x) >> j) & 1))
				bit |= (bit << ((1 << j) * i));
	}
	int mini = (bit[k] == 1 ? k : k + 1);
	int maxi = 0;
	while(k > 0 && t[0] > 0) {
		k -= 1;
		maxi += 2;
		t[0] -= 1;
	}
	maxi += min(t[1], k);
	printf("%d %d", mini, maxi);
	
	
	
	return 0;
}