#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, a[MAXN], b[MAXN], fen[MAXN];
set<int> st[MAXN];

void add(int v){for (v++; v<MAXN; v+=v&-v) fen[v]++;}
int gg(int v){
	int ret = 0;
	for (; v; v-=v&-v) ret += fen[v];
	return ret;
}

int get(int l, int r){
	r++;
	if (l < r) return (r-l)-(gg(r)-gg(l));
	return (n-(l-r))-(gg(MAXN-2)-(gg(l)-gg(r)));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], st[a[i]].insert(i);
	memcpy(b, a, sizeof(a));
	sort(b, b + n);
	ll ans = 0;
	int cur = 0;
	for (int i = 0; i < n; i++){
		int mn = b[i];
		auto it = st[mn].lower_bound(cur);
		if (it == st[mn].end()) it = st[mn].begin();
		int pos = *it;
		st[mn].erase(it);
		ans += get(cur, pos);
		cur = pos;
		add(cur);
	}
	cout << ans << "\n";
	return 0;
}