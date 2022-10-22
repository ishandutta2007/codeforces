#include<iostream>
#include<algorithm>
#include<numeric>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 100;

ll n, vec[MAXN], r[MAXN], h[MAXN], val[MAXN], d[MAXN], fen[MAXN];

bool cmp(ll u, ll v){return	val[u] < val[v];}

ll get(ll v){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret = max(ret, fen[v]);
	return	ret;
}

void add(ll v, ll x){
	for (v++; v < MAXN; v += v & (-v))
		fen[v] = max(fen[v], x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> r[i] >> h[i], val[i] = h[i] * r[i] * r[i];
	iota(vec, vec + n, 0);
	sort(vec, vec + n, cmp);
	ll ans = 0;
	for (ll i = 0; i < n;){
		int j = i;
		for (; i < n && val[vec[i]] == val[vec[j]]; i++){
			ll v = vec[i];
			d[v] = get(v) + val[v];
			ans = max(ans, d[v]);
		}
		for (; j < i; j++){
			ll v = vec[j];
			add(v, d[v]);
		}
	}	
		
	cout << fixed << setprecision(12);
	cout << ld(ans) * PI << "\n";
	return	0;
}