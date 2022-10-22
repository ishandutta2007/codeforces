#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 4e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, type[MAXN], p[MAXN], sec[MAXN], sz, ans[MAXN];
set<int> st, nonZero;

void add(int &x, int y){
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		if (s[1] == 'D')
			type[i] = 0;
		else
			type[i] = 1;

		cin >> p[i];
		sec[sz++] = p[i];
	}
	sec[sz++] = INF;
	sort(sec, sec + sz);
	for (int i = 0; i < n; i++)
		p[i] = lower_bound(sec, sec + sz, p[i]) - sec;

	ans[sz-1] = 1;
	st.insert(sz-1);
	nonZero.insert(sz-1);
	for (int i = 0; i < n; i++)
		if (!type[i]){
			auto it = st.lower_bound(p[i]);
			ans[p[i]] = ans[*it];
			st.insert(p[i]);
			nonZero.insert(p[i]);
		}
		else{
			st.erase(p[i]);
			auto it = st.lower_bound(p[i]);

			sz = 0;
			for (auto v:nonZero)
				if (v != p[i] && v != *it)
					sec[sz++] = v, ans[v] = 0;
			for (int i = 0; i < sz; i++)
				nonZero.erase(sec[i]);

			add(ans[*it], ans[p[i]]);
			ans[p[i]] = 0;
			nonZero.insert(*it);
		}

	int res = 0;
	for (int i = 0; i < MAXN; i++)
		add(res, ans[i]);
	cout << res << "\n";
	return 0;
}