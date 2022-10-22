
// Problem : E. Minimal Labels
// Contest : Educational Codeforces Round 25
// URL : https://codeforces.com/problemset/problem/825/E
// Memory Limit : 256.000000 MB
// Time Limit : 1000.000000 milisec
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e5+5;
int idg[MN], ans[MN];
vector<int> rev[MN];
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	set<int,greater<int>> s;
	while (m--) {
		int a,b; scanf ("%d %d",&a,&b);
		rev[b].push_back(a); ++idg[a];
	}
	for (int i = 1; i <= n; i++) if (!idg[i]) s.insert(i);
	for (int i = n; i >= 1; i--) {
		int take = *s.begin();
		s.erase(s.begin());
		ans[take] = i;
		for (int i : rev[take]) if (!(--idg[i])) s.insert(i);
	}
	for (int i = 1; i <= n; i++) printf ("%d%c",ans[i]," \n"[i==n]);
	return 0;
}