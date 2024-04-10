#include <bits/stdc++.h>
#define ll long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
	int mask; int rv; int cnt;
};

struct Hasher {

	int p; int mod; int n;
	vector<int> arr, pw, pref;
	vector<Vertex> rmq;

	void recalc(Vertex &a, Vertex &b) {
		int deg = pw[a.cnt];

		int m1 = ((ll) deg * b.mask) % mod;
		int m2 = ((ll) deg * b.rv) % mod;
		a.mask += m1, a.rv += m2;
		if (a.mask >= mod) a.mask -= mod;
		if (a.rv >= mod) a.rv -= mod;

		a.cnt += b.cnt;

	}

	void build(int i, int l, int r) {
		if (r-l == 1) {
			if (arr[l] == 0) return;
			rmq[i].mask = arr[l];
			rmq[i].rv = 3 - arr[l];
			rmq[i].cnt = 1;
			return;
		}

		int mid = (l+r)/2;
		build(2*i+1, l, mid);
		build(2*i+2, mid, r);
		rmq[i] = rmq[2*i+1];
		recalc(rmq[i], rmq[2*i+2]);

	}

	Hasher(int p_, int mod_, string x) {
		p = p_, mod = mod_, n = x.size();
		int now = 0;

		pref.push_back(0);

		for (int i = 0; i < x.size(); ++i) {
			pref.push_back(pref.back());
			if (x[i] == '1') {
				pref.back()++;
				arr.push_back(0);
				now ^= 1;
			}
			else arr.push_back(now+1);
		}

		pw.push_back(1);
		for (int i = 0; i < n+7; ++i) {
			pw.push_back(((ll) pw.back() * p) % mod);
		}

		rmq.assign(4*n, {0, 0, 0});
		build(0, 0, n);
	}

	void get(int i, int l, int r, int l1, int r1, Vertex &x) {
		if (l1 >= r1) return;
		if (l==l1 && r==r1) {
			recalc(x, rmq[i]);
			return;
		}
		int mid = (l+r)/2;
		get(2*i+1, l, mid, l1, min(r1, mid), x);
		get(2*i+2, mid, r, max(l1, mid), r1, x);
	}

	bool equal(int a, int b, int c, int d) {
		Vertex first = {0, 0, 0}, second = {0, 0, 0};
		get(0, 0, n, a, b+1, first);
		get(0, 0, n, c, d+1, second);


		int A = first.mask, B = second.mask;
		if (pref[a] % 2) A = first.rv;
		if (pref[c] % 2) B = second.rv;
		return (A==B);

	}



};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string x;
	cin >> x;

	Hasher first(179, 1000000007, x);
	Hasher second(239, 998244353, x);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int a, b, len;
		cin >> a >> b >> len;
		a--, b--;
		bool A = first.equal(a, a+len-1, b, b+len-1);
		bool B = second.equal(a, a+len-1, b, b+len-1);
		if (A&&B) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}

}