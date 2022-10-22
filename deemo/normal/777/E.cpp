//Where are you, hatter?

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, sec[MAXN], sz;
pair<pair<int, int>, int> a[MAXN];
ll ans, fen[MAXN];

bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y){
	if (x.F.S != y.F.S)
		return x.F.S > y.F.S;
	return x.F.F > y.F.F;
}

void upd(int v, ll val){for (v++; v < MAXN; v+=v&-v) fen[v]=max(fen[v],val);}
ll get(int v){ll ret = 0; for (; v; v-=v&-v) ret = max(ret, fen[v]); return ret;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i].F.F >> a[i].F.S >> a[i].S, sec[sz++] = a[i].F.F;
	sort(sec, sec + sz);
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++){
		auto x = a[i];
		int pos = lower_bound(sec, sec + sz, x.F.S) - sec;
		ll ret = x.S + get(pos);
		ans = max(ans, ret);
		pos = lower_bound(sec, sec + sz, x.F.F) - sec;
		upd(pos, ret);
	}
	cout << ans << "\n";
	return 0;
}