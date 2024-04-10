#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
  
using namespace std;

const int mod = 1e9 + 7;
const int nax = 1e5 + 111;

struct fen {
	int t[nax];
	
	void init() {
		FOR(i, 1, nax - 1)
			t[i] = 0;
	}
	
	void add(int x, int c) {
		for(; x < nax; x += x & -x)
			t[x] += c;
	}
	
	int daj(int x) {
		int res = 0;
		for(; x; x -= x & -x)
			res += t[x];
		return res;
	}
} ja[26];

char s[nax];

int main() {
	FOR(i, 0, 25)
		ja[i].init();
	scanf("%s", s + 1);
	FOR(i, 1, (int)strlen(s + 1))
		ja[s[i] - 'a'].add(i, 1);
	int q;
	int a, b;
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d", &a, &b);
		if(a == 1) {
			char c;
			scanf(" %c", &c);
			ja[s[b] - 'a'].add(b, -1);
			ja[c - 'a'].add(b, 1);
			s[b] = c;
		}
		else {
			int c;
			scanf("%d", &c);
			int ans = 0;
			FOR(j, 0, 25) {
				if(ja[j].daj(c) - ja[j].daj(b - 1) > 0)
					ans += 1;
			}
			printf("%d\n", ans);
		}
	}
		
	
	return 0;
}