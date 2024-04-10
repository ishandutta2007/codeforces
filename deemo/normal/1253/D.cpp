#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m, par[MAXN];
int lst[MAXN];
int mn[MAXN], mx[MAXN];
pii sec[MAXN]; int sz;

int getPar(int v){return par[v]==v? v: par[v]=getPar(par[v]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	iota(par, par + n, 0);
	while (m--){
		int u, v; cin >> u >> v, u--, v--;
		par[getPar(u)] = getPar(v);
	}
	memset(mn, 63, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	for (int i = 0; i < n; i++){
		int v = getPar(i);
		mn[v] = min(mn[v], i);
		mx[v] = max(mx[v], i);
	}
	for (int i = 0; i < n; i++)
		if (getPar(i) == i)
			sec[sz++] = {mn[i], mx[i]};

	int ans = 0;
	sort(sec, sec + sz);
	int lst = -1;
	for (int i = 0; i < sz; i++){
		if (lst > sec[i].F)
			ans++;
		lst = max(lst, sec[i].S);
	}
	cout << ans << "\n";
	return 0;
}