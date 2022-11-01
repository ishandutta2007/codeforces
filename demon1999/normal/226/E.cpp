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

struct seg_tree {
	seg_tree *l, *r;
	int k;
	seg_tree() {
		k = 0; 
		l = r = NULL;
	}
};


typedef seg_tree * seg_tree_uk;

seg_tree_uk make_segment_tree(int l, int r, int pp) {
	seg_tree_uk we = new seg_tree();
	if (r - l == 1) {
		//if (l >= pp)
		//	(we->k) = 1;
		re we;
	}
	int mid = (l + r) / 2;
	(we->l) = make_segment_tree(l, mid, pp);
	(we->r) = make_segment_tree(mid, r, pp);
	//(we->k) = ((we->l)->k) + ((we->r)->k);
	re we;
}

seg_tree_uk new_vers(seg_tree_uk root, int l, int r, int k) {
	seg_tree_uk we = new seg_tree();
	if (r - l == 1) {
		(we -> k) = 1;
		re we;
	}
	int mid = (l + r) / 2;
	if (k < mid) {
		we->l = new_vers(root->l, l, mid, k);
		we->r = root->r;
	}
	else {
		we->l = root->l;
		we->r = new_vers(root->r, mid, r, k);
	}
	we->k = ((we->l)->k) + ((we->r)->k);
	//cout << (we->k) << " " << l << " " << r << " " << k << endl;
	re we;
}

const ll szz = 131072, szz1 = 8, buben = 200000000, inf = ll(1e9);

vector<int> e[szz];

int size_of_subtr[szz], tt = 0, tin[szz], tout[szz], num_path[szz], num_in_path[szz], pr[20][szz], n;

struct path {
	int size_;
	vector<int> nums;
	vector<int> times;
	vector<seg_tree_uk> vers;
	path() {
		nums.resize(0);
		times.assign(1, 0);
		vers.resize(0);
		size_ = 1;
	}
};

vector<int> path_pr, num_path_pr;
vector<path> qq;

void dfs(int nu, int p) {
	pr[0][nu] = p;
	//cout << nu << " " << p << " " << pr[0][nu] << endl;
	tin[nu] = tt;
	tt++;
	for (int i = 1; i < 20; i++)
		pr[i][nu] = pr[i - 1][pr[i - 1][nu]];
	size_of_subtr[nu] = 1;
	for (int v : e[nu]) {
		dfs(v, nu);
		size_of_subtr[nu] += size_of_subtr[v];
	}
	tout[nu] = tt;
	tt++;
}

void dfs1(int nu, int nu_path) {
	num_path[nu] = nu_path;
	qq[nu_path].nums.push_back(nu);
	num_in_path[nu] = sz(qq[nu_path].nums);
	int nuk = -1;
	for (int v : e[nu])
		if (nuk == -1 || size_of_subtr[v] > size_of_subtr[nuk])
			nuk = v;
	for (int v : e[nu]) {
		if (v != nuk) {
			qq.push_back(path());
			path_pr.push_back(nu_path);
			num_path_pr.push_back(nu);
			dfs1(v, sz(qq) - 1);
		}
		else
			dfs1(v, nu_path);
	}
}

ll get_sum(seg_tree_uk a, seg_tree_uk b, int l, int r, int ql, int qr) {
	if (r <= ql || l >= qr) re 0;
	if (ql <= l && r <= qr) {
		re abs((a->k) - (b->k));
	}
	int mid = (l + r) / 2;
	int sum =  get_sum((a->l), (b->l), l, mid, ql, qr) + get_sum((a->r), (b->r), mid, r, ql, qr);
	//cout << l << " " << r << " " << sum << endl; 
	re sum;
}

ll get_(seg_tree_uk a, seg_tree_uk b, int l, int r, int k) {
	//cout << l << " " << r << " " << k << endl;
	if (l + 1 == r)
		re l;
	int mid = (l + r) / 2;
	int p = mid - l - abs(((a->r)->k) - ((b->r)->k));
	if (k <= p) 
		re get_((a->r), (b->r), mid, r, k);
	re get_((a->l), (b->l), l, mid, k - p);
}

int go(int a, int b, int &k, int y) {
	while (num_path[a] != num_path[b]) {
		int p = num_path[a];
		int numv = upper_bound(qq[p].times.begin(), qq[p].times.end(), y) - qq[p].times.begin() - 1;
		int kk = num_in_path[a] - get_sum(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, 
				qq[p].size_, qq[p].size_ + num_in_path[a]);
		if (kk < k) {
			k -= kk;
			a = num_path_pr[p];
			continue;
		}
		int pp = qq[p].size_ - num_in_path[a] - get_sum(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, 
			qq[p].size_ + num_in_path[a], 2 * qq[p].size_);
		k += pp;
		re qq[p].nums[-qq[p].size_ + get_(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, k)] + 1;
		
	}
	//cout << k << " " << a << endl;
	int p = num_path[a];
	int numv = upper_bound(qq[p].times.begin(), qq[p].times.end(), y) - qq[p].times.begin() - 1;
	int kk = num_in_path[a] - num_in_path[b] + 1 - get_sum(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, 
			qq[p].size_ + num_in_path[b] - 1, qq[p].size_ + num_in_path[a]);
	//cout << kk << endl;
	if (k <= kk) {
		int pp = qq[p].size_ - num_in_path[a] - get_sum(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, 
			qq[p].size_ + num_in_path[a], 2 * qq[p].size_);
		k += pp;
		//cout << k << endl;
		re 1 + qq[p].nums[- qq[p].size_ + get_(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, k)];
	}
	k -= kk;
	re 0;
}

int get_sum1(int a, int b, int y) {
	int ans = 0;
	while (num_path[a] != num_path[b]) {
		int p = num_path[a];
		int numv = upper_bound(qq[p].times.begin(), qq[p].times.end(), y) - qq[p].times.begin() - 1;
		int kk = num_in_path[a] - get_sum(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, 
				qq[p].size_, qq[p].size_ + num_in_path[a]);
		ans += kk;
		a = num_path_pr[p];
	}
	int p = num_path[a];
	int numv = upper_bound(qq[p].times.begin(), qq[p].times.end(), y) - qq[p].times.begin() - 1;
	//cout << numv << endl;
	//re 0;
	//exit(0);
	int kk = num_in_path[a] - num_in_path[b] + 1 - get_sum(qq[p].vers[numv], qq[p].vers[sz(qq[p].vers) - 1], qq[p].size_, 2 * qq[p].size_, 
			qq[p].size_ + num_in_path[b] - 1, qq[p].size_ + num_in_path[a]);
	//cout << kk << " heh\n";
	ans += kk;
	re ans;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	int nu = 0;
	forn (i, n) {
		int pr;
		cin >> pr;
		if (pr) {
			e[pr - 1].push_back(i);
		}
		else
			nu = i;
	}
	dfs(nu, nu);
	qq.push_back(path());
	path_pr.push_back(-1);
	num_path_pr.push_back(-1);
	dfs1(nu, 0);
	//re 0;
	forn (i, sz(qq)) {
		while (qq[i].size_ < sz(qq[i].nums)) {
			qq[i].size_ *= 2;
		}
		qq[i].vers.push_back(make_segment_tree(qq[i].size_, 2 * qq[i].size_, sz(qq[i].nums)));
	}
	//re 0;
	//puts("KEK");
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int t, a, b, k, y;
		cin >> t >> a;
		a--;
		if (t == 1) {
			seg_tree_uk pp = qq[num_path[a]].vers[sz(qq[num_path[a]].vers) - 1];
			qq[num_path[a]].vers.push_back(new_vers(pp, qq[num_path[a]].size_, 2 * qq[num_path[a]].size_, qq[num_path[a]].size_ + num_in_path[a] - 1));
			qq[num_path[a]].times.push_back(i);
			continue;
		}
		cin >> b >> k >> y;
		b--;
		//cout << b << " " << a << endl;
		//cout << "0\n";
		if (a == b) {
			cout << -1 << "\n";
			continue;
		}
		if (pr[0][b] == a || pr[0][a] == b) {
			cout << -1 << "\n";
			continue;
		}
		
		if ((!(tin[a] <= tin[b] && tout[b] <= tout[a])) && (!(tin[b] <= tin[a] && tout[a] <= tout[b]))) { 
			a = pr[0][a]; b = pr[0][b];
		}
		else {
			bool ok = false;
			if (tin[a] <= tin[b] && tout[b] <= tout[a]) {
				ok = true;
				swap(a, b);
			}
			int num = a;
			//cout << num << endl;
			for (int i = 19; i >= 0; i--) {
				if (tin[pr[i][num]] <= tin[b] && tout[b] <= tout[pr[i][num]]) {
					continue;
				}
				//cout << i << " " << num << " hoho \n" << pr[0][num] << endl;
				num = pr[i][num];
			}
			//cout << num << endl;
			b = num;
			a = pr[0][a];
			if (ok) swap(a, b);
		}
		//cout << a << " " << b << endl;
		if (!(tin[a] <= tin[b] && tout[b] <= tout[a])) {
			int num = a;
			for (int i = 19; i >= 0; i--) {
				if (tin[pr[i][num]] <= tin[b] && tout[b] <= tout[pr[i][num]]) continue;
				num = pr[i][num];
			}
			//cout << num << endl;
			int kk = get_sum1(a, num, y);
			//cout << kk << endl;
			if (kk >= k) {
				//cout << "HUI\n";
				//k = kk - k + 1;
				cout << go(a, num, k, y) << "\n";
				continue;
			}
			k -= kk;
			a = pr[0][num];
		}
		//continue;
		//cout << endl;
		int kk = get_sum1(b, a, y);
		//re 0;
		//continue;
		if (kk < k) {
			cout << "-1\n";
			continue;
		}
		//cout << k << " heh\n";
		k = kk - k + 1;
		//cout << k << endl;
		cout << go(b, a, k, y) << "\n";
		//re 0;
	}
	re 0;
}