#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
const ll inf = ll(1e9) * ll(1e9);

ll n, m, sum1;
int ans[100001], cnt[100001], lst[100001];
queue<pair<pair<ll, ll>, ll> > tek[100001];
vector<ll> a, pr, b[100001], pos, seg_tree[100001], str1[100001];

ll my_gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		re a;
	}
	if (a < b)
		re my_gcd(b, a, y, x);
	ll xx = 0, yy = 0;
	ll ans = my_gcd(b, a % b, xx, yy);
	x = yy;
	y = xx - (a / b) * yy;
	re ans;
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m;
	forn (i, n) {
		int k;
		cin >> k;
		b[i].resize(k);
		forn (j, k) {
			cin >> b[i][j];
			b[i][j]--;
			cnt[b[i][j]]++;
		}
	}
	forn (i, m) {
		int kk = 1;
		while (kk < cnt[i])
			kk *= 2;
		seg_tree[i].assign(2 * kk, 1);
		str1[i].assign(2 * kk, 0);
		pos.push_back(kk);
	}
	forn (i, n) {
		ll k = sz(b[i]);
		a = b[i];
		forn (j, k) {
			while (!tek[a[j]].empty()) {
				ll kk = seg_tree[a[j]][1];
				ll pp = str1[a[j]][1];
				//cout << pp << endl;
				if (lst[a[j]] == i - 1 && pp % __gcd(kk, k) == j % __gcd(kk, k)) {
					break;
				} 		
				int nu = tek[a[j]].front().se;
				tek[a[j]].pop();
				seg_tree[a[j]][nu] = 1;
				str1[a[j]][nu] = 0;
				while (nu / 2) {
					nu /= 2;
					ll x = 0, y = 0;
					ll aa = seg_tree[a[j]][2 * nu], bb = seg_tree[a[j]][2 * nu + 1];
					ll kk = my_gcd(aa, bb, x, y);
					//cout << kk << " " << x * aa << " " << y * bb << "\n";
					seg_tree[a[j]][nu] = (aa / kk) * bb;
					x *= ((str1[a[j]][2 * nu + 1] - str1[a[j]][2 * nu]) / kk);
					x %= (seg_tree[a[j]][nu] / seg_tree[a[j]][2 * nu]);
					str1[a[j]][nu] = ((x * aa + str1[a[j]][2 * nu]) % seg_tree[a[j]][nu] + seg_tree[a[j]][nu]) %
						seg_tree[a[j]][nu];
				}
			}
			lst[a[j]] = i;
			tek[a[j]].push(mp(mp(k, j), pos[a[j]]));
			seg_tree[a[j]][pos[a[j]]] = k;
			str1[a[j]][pos[a[j]]] = j;
			int nu = pos[a[j]];
			while (nu / 2) {
				nu /= 2;
				ll x = 0, y = 0;
				ll aa = seg_tree[a[j]][2 * nu], bb = seg_tree[a[j]][2 * nu + 1];
				ll kk = my_gcd(aa, bb, x, y);
				//cout << kk << " " << x * aa << " " << y * bb << "\n";
				seg_tree[a[j]][nu] = (aa / kk) * bb;
				x *= ((str1[a[j]][2 * nu + 1] - str1[a[j]][2 * nu]) / kk);
				x %= (seg_tree[a[j]][nu] / seg_tree[a[j]][2 * nu]);
				str1[a[j]][nu] = ((x * aa + str1[a[j]][2 * nu]) % seg_tree[a[j]][nu] + seg_tree[a[j]][nu]) %
					seg_tree[a[j]][nu];
			}
			pos[a[j]]++;
			ans[a[j]] = max(ans[a[j]], sz(tek[a[j]]));
		}
	}
	forn (i, m) {
		cout << ans[i] << endl;
	}
	re 0;
}