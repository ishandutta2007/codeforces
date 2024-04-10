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

const ll mod = int(1e9) + 7, pq = 2, szz = 131072, szz1 = 8;

struct seg_tree {
	seg_tree *l, *r;
	ll hash, lst_null;
	seg_tree() {
		l = r = NULL;
		hash = lst_null = 0;
	}
};

typedef seg_tree* seg_ptr;
struct seg_ptr1
{
	seg_ptr iam;
	seg_ptr1() {
	}
	seg_ptr1(seg_ptr a) {
		iam = a;
	}
};

int n, m, s, f, pr[szz];
seg_ptr dist[szz], zero_tree, one_tree;

set<pair<int, seg_ptr1> > a;

vector<ll> p;
vector<pair<int, int> > e[szz];

seg_ptr make_(int l, int r, int k) {
	seg_ptr we = new seg_tree();
	if (l + 1 == r) {
		we->hash = k;
		if (k == 0)
			(we->lst_null) = l - szz;
		re we;
	}
	int mid = (l + r) / 2;
	(we->l) = make_(l, mid, k);
	(we->r) = make_(mid, r, k);
	(we->hash) = (((we->l)->hash) * p[r - mid] + ((we->r)->hash)) % mod;
	(we->lst_null) = max(((we->l)->lst_null), ((we->r)->lst_null));
	re we;
}

int get_lst(seg_ptr ro, int l, int r, int ql, int qr) {
	if (qr <= l || r <= ql) re 0;
	if (ql <= l && r <= qr) {
		re ro->lst_null;
	}
	int mid = (l + r) / 2;
	re max(get_lst((ro->l), l, mid, ql, qr), get_lst((ro->r), mid, r, ql, qr));
}

seg_ptr new_(seg_ptr t, int l, int r, int num) {
	seg_ptr we = new seg_tree();
	if (l + 1 == r) {
		we->hash = 1;
		we->lst_null = 0;
		re we;
	}
	int mid = (l + r) / 2;
	(we->l) = t->l;
	(we->r) = t->r;
	if (num < mid)
		we->l = new_((t->l), l, mid, num);
	else
		we->r = new_((t->r), mid, r, num);
	(we->hash) = (((we->l)->hash) * p[r - mid] + ((we->r)->hash)) % mod;
	(we->lst_null) = max(((we->l)->lst_null), ((we->r)->lst_null));
	re we;
}

seg_ptr new2_(seg_ptr a, seg_ptr por, int l, int r, int ql, int qr) {
	if (r <= ql || l >= qr) re a;
	if (ql <= l && r <= qr) {
		re por;
	}
	seg_ptr we = new seg_tree();
	int mid = (l + r) / 2;
	we->l = new2_((a->l), (por->l), l, mid, ql, qr);
	we->r = new2_((a->r), (por->r), mid, r, ql, qr);
	(we->hash) = (((we->l)->hash) * p[r - mid] + ((we->r)->hash)) % mod;
	(we->lst_null) = max(((we->l)->lst_null), ((we->r)->lst_null));
	re we;
}

bool func(seg_ptr a, seg_ptr b, int l, int r) {
	if (l + 1 == r) {
		re (a->hash) < (b->hash);
	}
	int mid = (l + r) / 2;
	if (((a->l)->hash) != ((b->l)->hash))
		re func((a->l), (b->l), l, mid);
	else
		re func((a->r), (b->r), mid, r);
}

bool operator < (seg_ptr1 a, seg_ptr1 b) {
	re func(a.iam, b.iam, szz, 2 * szz);
}
 
bool operator < (pair<int, seg_ptr1> a, pair<int, seg_ptr1> b) {
	re (a.se < b.se || ((a.se.iam->hash) == (b.se.iam->hash) && a.fi < b.fi));
} 

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> m;
	p.assign(2 * szz, 1);
	forn (i, 2 * szz - 1)
		p[i + 1] = (p[i] * pq) % mod;
	forn (i, m) {
		int a, b, we;
		cin >> a >> b >> we;
		a--;
		b--;
		we = szz - we  - 1;
		e[a].push_back(mp(b, we));
		e[b].push_back(mp(a, we));
	}
	cin >> s >> f;
	s--;
	f--;
	zero_tree = make_(szz, 2 * szz, 0);
	one_tree = make_(szz, 2 * szz, 1);
	forn (i, n) {
		pr[i] = -1;
		dist[i] = one_tree;
		if (i == s) dist[i] = zero_tree;
		a.insert(mp(i, seg_ptr1(dist[i])));
	}
	pr[s] = s;
	forn (i, n) {
		int num = (a.begin()->fi);
		a.erase(a.begin());
		if (pr[num] == -1)
			break;
		//cout << num << " " << i << " I'm nod a God, so my code isn't ideal, but I know, that I can debag it\n";
		for (auto v : e[num]) {
			seg_ptr qq = dist[num];
			int nu = get_lst(qq, szz, 2 * szz, szz, szz + v.se + 1);
			//exit(0);
			qq = new2_(new_(qq, szz, 2 * szz, nu + szz), zero_tree, szz, 2 * szz, szz + nu + 1, szz + v.se + 1);
			if (seg_ptr1(qq) < seg_ptr1(dist[v.fi])) {
				//cout << "HOh\n";
				pr[v.fi] = num;
				a.erase(mp(v.fi, seg_ptr1(dist[v.fi])));
				dist[v.fi] = qq;
				a.insert(mp(v.fi, seg_ptr1(dist[v.fi])));
			}
		}
		//exit(0);
	}
	if (pr[f] == -1) {
		cout << -1;
		re false;
	}
	cout << (dist[f]->hash) << "\n";
	vector<int> ans;
	int nu = f;
	while (true) {
		ans.push_back(nu);
		if (nu == s) break;
		nu = pr[nu];
	}
	reverse(ans.begin(), ans.end());
	cout << sz(ans) << "\n";
	forn (i, sz(ans))
		cout << ans[i] + 1 << " ";
	cout << "\n";
	re 0;
}