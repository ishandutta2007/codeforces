#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int MAX_VAL = (int)1e9 + 7;

int q, x[MAXN], sec[MAXN], sz;
char t[MAXN];
ll seg[MAXN << 2];
int cnt[MAXN << 2];

void ins(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		cnt[v] += val;
		seg[v] += val*sec[b];
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		ins(v<<1, b, mid, pos, val);
	else
		ins(v<<1^1, mid, e, pos, val);
	seg[v] = seg[v<<1] + seg[v<<1^1];
	cnt[v] = cnt[v<<1] + cnt[v<<1^1];
}

set<pii> st;
pair<ll, ll> get(int v, int b, int e, int pos, ll sm = 0){
	if (e - b == 1)
		return {sm, sm + seg[v]};

	int mid = b + e >> 1;
	if (pos < mid)
		return get(v<<1, b, mid, pos, sm);
	return get(v<<1^1, mid, e, pos, sm+seg[v<<1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> t[i] >> x[i];
		sec[sz++] = x[i];
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;

	for (int i = 0; i < q; i++) {
		if (t[i] == '+'){
			int pos = lower_bound(sec, sec + sz, x[i]) - sec;
			st.insert({x[i], i});
			ins(1, 0, sz, pos, 1);
		}
		else{
			int pos = lower_bound(sec, sec + sz, x[i]) - sec;
			st.erase(st.lower_bound({x[i], -1}));
			ins(1, 0, sz, pos, -1);
		}

		int ans = max(0, (int)st.size()-1);

		if (ans){
			ll lst = 0;
			while (true){
				auto it = st.upper_bound({(int)(lst<<1)+1, -1});
				if (it == st.end()) break;

				int pos = lower_bound(sec, sec + sz, it->F) - sec;
				auto x = get(1, 0, sz, pos);
				if (lst && x.F*2 < it->F) ans--;
				lst = x.S;
				if (lst > MAX_VAL) break;
			}
		}

		cout << ans << "\n";
	}
	return 0;
}