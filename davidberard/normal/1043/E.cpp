#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct person {
	ll x, y, orig;
	person() {}
	person(ll a, ll b, ll o) : x(a), y(b), orig(o) {}
	bool operator< (const person& o) const {
		return (y-x) < (o.y-o.x);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll N, M;
	cin >> N >> M;
	vector<person> v(N);
	vector<person> orig(N);
	ll ii = 0;
	for(auto& x : v) {
		cin >> x.x >> x.y;
		x.orig = ii++;
		orig[ii-1].x = x.x;
		orig[ii-1].y = x.y;
	}
	sort(v.begin(), v.end());
	vector<ll> xpfx(N+1, 0);
	vector<ll> ypfx(N+1, 0);
	vector<ll> ans(N, 0);
	for(ll i=0;i<N;++i) {
		xpfx[i+1] = xpfx[i]+v[i].x;
		ypfx[i+1] = ypfx[i]+v[i].y;
	}

	for(ll i=0;i<N;++i)
	{
		ll splt = i;
		ans[v[i].orig] += ypfx[splt]+v[i].x*splt;
		ans[v[i].orig] += xpfx[N]-xpfx[splt]+v[i].y*(N-splt);
	}

	for(ll i=0;i<N;++i) {
		ans[v[i].orig] -= v[i].x+v[i].y;
	}
	for(ll i=0;i<M;++i) {
		ll a, b;
		cin >> a >> b;
		--a; --b;
		ll vv = min(orig[a].x+orig[b].y, orig[a].y+orig[b].x);
		ans[a] -= vv;
		ans[b] -= vv;
	}
	for(auto& x : ans) cout << x << " ";
	cout << endl;
	
	return 0;
}