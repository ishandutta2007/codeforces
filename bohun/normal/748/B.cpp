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
char s[2][1005];
int n;
vector <pair<int, int>> res;
int ile[30], mapa[30][30];
 
int main() {
	scanf("%s%s", s[0], s[1]);
	n = strlen(s[0]);
	FOR(i, 0, n - 1) {
		int a = s[0][i] - 'a' + 1;
		int b = s[1][i] - 'a' + 1;
		if(ile[a] && mapa[a][b] != 1) {
			printf("-1\n");
			return 0;
		}
		if(ile[b] && mapa[b][a] != 1) {
			printf("-1\n");
			return 0;
		}
		if(!ile[a] && !ile[b] && a != b)
			res.pb(mp(a, b));
		ile[a] += 1;
		ile[b] += 1;
		mapa[a][b] = mapa[b][a] = 1;
	}
	
	printf("%d\n", ss(res));
	for(auto it : res)
		printf("%c %c\n", (char) (it.fi + 'a' - 1), (char) ('a' -1 + it.se));
		
		
	
	
	
	return 0;
}