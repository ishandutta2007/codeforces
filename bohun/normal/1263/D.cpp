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

int n;
char s[210005];
vector <int> v[210005];
int ans = 0; 
bool odw[210005];

void dfs(int u) {
	odw[u] = 1;
	for(auto it : v[u])
		if(!odw[it])	
			dfs(it);
}
	
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s);
		for(int j = 0; j < (int) strlen(s); ++j) {
			int c = s[j] - 'a';
			v[i + 30].pb(c);
			v[c].pb(i + 30);
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!odw[i + 30]) {
			ans++;
			dfs(i + 30);
		}
	printf("%d", ans);
	
	
	
	
	return 0;
}