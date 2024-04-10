
#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int bub = 500, bub2 = 700;
int n, q;
int cnt[300][100000];
vector<int> bl[10000];

void make_decomp() {
	vector<int> a;
	forn (i, n / bub + 10) {
		for (int v : bl[i]) {
			cnt[i][v]--;
			a.push_back(v);
		}
		bl[i].resize(0);
	}
	forn (i, n) {
		bl[i / bub].push_back(a[i]);
		cnt[i / bub][a[i]]++;
	}
}

void shift(int l, int r) {
	if (l == r) re;
	int sum = 0, a;
	forn (i, n / bub + 10) {
		if (r <= sum + sz(bl[i])) {
			int pos = r - sum - 1;
			a = bl[i][pos];
			for (int j = pos; j + 1 < sz(bl[i]); j++)
				bl[i][j] = bl[i][j + 1];
			bl[i].pop_back();
			cnt[i][a]--;
			break;
		}
		sum += sz(bl[i]);
	}
	sum = 0;
	forn (i, n / bub + 10) {
		if (l <= sum + sz(bl[i])) {
			int pos = l - sum - 1;
			cnt[i][a]++;
			bl[i].push_back(a);
			for (int j = sz(bl[i]) - 1; j > pos; j--)
				swap(bl[i][j], bl[i][j - 1]);
			break;
		}
		sum += sz(bl[i]);
	}
	/*
	forn (i, n / bub + 10)
		for (int v : bl[i])
			cout << v << " ";
	cout << "\n";*/
}

int get_ans(int l, int r, int k) {
	int ans = 0, sum = 0;
	//cout << l << " " << r << " " << k << endl;
	forn (i, n / bub + 10) {
		if (l <= sum + 1 && r >= sum + sz(bl[i])) {
			ans += cnt[i][k];
		}
		else {
			if (l > sum + sz(bl[i]) || r < sum + 1) {

			} else
			forn (j, sz(bl[i])) {
				if (bl[i][j] == k && sum + j + 1 >= l && sum + j + 1 <= r)
					ans++;
			}
		}
		sum += sz(bl[i]);
	}
	re ans;
}
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//scanf("%d%d%d%d", &n, &m, &q, &k);
	//cin >> n;
	scanf("%d", &n);
	forn (i, n) {
		int a;
		scanf("%d", &a);
		//cin >> a;
		cnt[i / bub][a - 1]++;
		bl[i / bub].push_back(a - 1);
	}
	scanf("%d", &q);
	int cnt = 0, ans = 0;
	forn (i, q) {
		int t, l, r, k;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			cnt++;
			l = (l + ans - 1) % n + 1;
			r = (r + ans - 1) % n + 1;
			if (l > r)
				swap(l, r);
			shift(l, r);
			if (cnt == bub2) {
				make_decomp();
				cnt = 0;
			}
			//printf("%d\n", &ans);
		} else {
			scanf("%d\n", &k);
			l = (l + ans - 1) % n + 1;
			r = (r + ans - 1) % n + 1;
			k = (k + ans - 1) % n;
			//k--;
			if (l > r)
				swap(l, r);
			ans = get_ans(l, r, k);
			printf("%d\n", ans);
		}
	}
}