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

const int nax = 2e5 + 111;
const int mod = 1e9 + 7;

string s = "Bulbasaur";
char c[nax];
int n;
map <char, int> elo;

int main() {
	int ans = 0;
	scanf("%s", c + 1);
	n = strlen(c + 1);
	for(int i = 1; i <= n; ++i) {
		elo[c[i]] += 1;
	}
	ans = 1e9;
	ans = min(ans, elo['B']);
	ans = min(ans, elo['u'] / 2);
	ans = min(ans, elo['l']);
	ans = min(ans, elo['b']);
	ans = min(ans, elo['a'] / 2);
	ans = min(ans, elo['s']);
	ans = min(ans, elo['r']);
	
	printf("%d", ans);
		
	return 0;
}