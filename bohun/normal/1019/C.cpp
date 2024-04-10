#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int nax = 1e6 + 111;

unordered_set <int> s;

int n, m;
vector <int> in[nax], out[nax];
int a, b;
int killed[nax];
int need[nax];

void solve() {
	if(ss(s) == 0)
		return;
	int u = *s.begin();
	killed[u] = 1;
	s.erase(s.begin());
	vector <int> fr, gao;
	for(auto it : out[u]) 
		if(!killed[it]) {
			fr.pb(it);
			killed[it] = 1;
			s.erase(s.find(it));
		}
	for(auto it : in[u])
		if(!killed[it])
			gao.pb(it);
	solve();
	bool black = 0;
	for(auto it : gao)
		if(need[it] == 1)
			black = 1;
	if(!black) {
		need[u] = 1;
	}
	else {
		need[u] = 0;
	}
}
	

int main() {
	scanf("%d %d", &n, &m);
	FOR(i, 1, m) {
		scanf("%d %d", &a, &b);
		in[b].pb(a);
		out[a].pb(b);
	}
	FOR(i, 1, n)
		s.insert(i);
	solve();
	vector <int> ans;
	FOR(i, 1, n)
		if(need[i])
			ans.pb(i);
	printf("%d\n", ss(ans));
	for(auto it : ans)
		printf("%d ", it);
	
	
	
	return 0;
}