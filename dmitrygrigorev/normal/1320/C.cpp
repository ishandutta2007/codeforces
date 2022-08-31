#include <bits/stdc++.h>
#define data dkfjdskjf
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1000007;

vector<ll> rmq, ps;

struct Monster{int x; int y; int z;};

bool cmp(Monster &a, Monster &b) {
	return (a.x < b.x);
}

void push(int i, int l, int r) {
	if (r-l <= 1) return;

	ll p = ps[i];
	if (p==0) return;
	ps[i] = 0;
	rmq[2*i+1]+=p, rmq[2*i+2]+=p, ps[2*i+1]+=p, ps[2*i+2]+=p;

}

void add(int i, int l, int r, int l1, int r1, int val, bool pers) {

	push(i, l, r);
	if (l1 >= r1) return;
	if (l==l1 && r==r1) {
		if (pers) {
			rmq[i] = 0;
		}
		rmq[i] += val, ps[i] += val;
		return;
	}
	int mid = (l+r)/2;
	add(2*i+1, l, mid, l1, min(r1, mid), val, pers);
	add(2*i+2, mid,r , max(l1, mid), r1, val, pers);
	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;

	rmq.assign(4*N, -1e18);
	ps.assign(4*N, 0);

	vector<pair<int, int> > attack, shield;
	vector<Monster> mons;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		attack.push_back({x, y});
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		shield.push_back({x, y});
	}

	for (int i = 0; i < p; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		mons.push_back({x, y, z});
	}

	sort(attack.begin(), attack.end());
	for (int i = 0; i < shield.size(); ++i) {
		add(0, 0, N, shield[i].first, shield[i].first + 1, -shield[i].second, true);
	}
	sort(mons.begin(), mons.end(), cmp);

	int u = 0;
	ll ans = -1e18;
	for (int i = 0; i < attack.size(); ++i) {
		while (u < mons.size() && mons[u].x < attack[i].first) {
			add(0, 0, N, mons[u].y+1, N, mons[u].z, false);
			u++;
		}

		ans = max(ans, (ll) -attack[i].second + rmq[0]);

	}

	cout << ans;


}