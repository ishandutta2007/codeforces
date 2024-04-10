#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int nax = 5e5 + 11;

int n;
int x[nax];
char c[nax];
map <char, int> typ;

int go(int k, int w) {
	for(int i = 1; i <= n; ++i) {
		if(typ[c[i]] == 0) 
			w |= ((x[i] >> k) & 1);
		if(typ[c[i]] == 1)
			w ^= ((x[i] >> k) & 1);
		if(typ[c[i]] == 2)
			w &= ((x[i] >> k) & 1);
	}
	return w;
}

int mask[3];

int main() {
	typ['|'] = 0;
	typ['^'] = 1;
	typ['&'] = 2;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf(" %c %d", &c[i], &x[i]);
	}
	for(int i = 0; i < 10; ++i) {
		int a = go(i, 0);
		int b = go(i, 1);
		if(a == 0 && b == 1)
			mask[2] |= (1 << i);
		if(a == 1 && b == 0) {
			mask[1] |= (1 << i);
			mask[2] |= (1 << i);
		}
		if(a == 1 && b == 1) {
			mask[0] |= (1 << i);
			mask[2] |= (1 << i);
		}
	}
	printf("3\n");
	printf("| %d\n", mask[0]);
	printf("^ %d\n", mask[1]);
	printf("& %d\n", mask[2]);
	return 0;
}