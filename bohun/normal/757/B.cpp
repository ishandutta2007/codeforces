#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 1e5 + 111;
const int mod = 1e9 + 7;

int ile[nax];
int odp[nax];

int ans, a, n;


int main() {
	scanf("%d", &n);
	FOR(i, n) {
		scanf("%d", &a);
		ile[a] += 1;
	}
	for(int i = 2; i <= nax - 1; ++i) {
		int elo = 0;
		for(int j = i; j < nax; j += i)
			elo += ile[j];
		ans = max(ans, elo);
	}
	printf("%d", max(ans, 1));
	return 0;
}