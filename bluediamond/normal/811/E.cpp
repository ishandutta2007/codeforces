#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 

bool home = true;
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 7;
const int SZ = 10;
int sz, n, q, a[SZ][N], from[N], to[N], print[N], papa[N * SZ], last[N * SZ], tt, chompy[SZ][N], king[N];
vector<int> inds[N];
int comps;


int root(int a) {
	if (papa[a] == a) return a;
	return papa[a] = root(papa[a]);
}

void join(int a, int b) {

	if (last[a] < tt) {
		comps++;
		last[a] = tt;
		papa[a] = a;
	}

	if (last[b] < tt) {
		comps++;
		last[b] = tt;
		papa[b] = b;
	}

	a = root(a);
	b = root(b);

	if (a == b) return;
	comps--;


	papa[a] = b;
}

bool cmp_inds(int i, int j) {
	return to[i] < to[j];
}

int getid(int i, int j) {
	return i * n + j;
}

void fixall(int pos, int ref) {
	for (int r = 0; r < sz; r++) {
		int a = getid(r, pos);
		if (last[a] < tt) {
			comps++;
			last[a] = tt;
			papa[a] = a;
		}

	}
	for (int r = 1; r < sz; r++) {
		if (a[r][pos] == a[r - 1][pos]) {
			join(getid(r, pos), getid(r - 1, pos));
		}
	}
	king[pos] = comps;
	for (int r = 0; r < sz; r++) {
		chompy[r][pos] = root(getid(r, ref));
	}
}

void rec(int low, int high) {
	if (low == high) {
		vector<int> extracted;
		while (!inds[low].empty()) {
			int i = inds[low].back();
			extracted.push_back(i);
			inds[low].pop_back();
			assert(from[i] == low);
			assert(to[i] == low);
		}

		int current = 1;
		for (int i = 1; i < sz; i++) {
			current += (a[i][low] != a[i - 1][low]);
		}
		for (auto& i : extracted) {
			print[i] = current;
		}
		return;
	}
	int mid = (low + high) / 2;
	vector<int> extracted;
	for (int l = low; l <= mid; l++) {
		while (!inds[l].empty()) {
			int i = inds[l].back();
			assert(from[i] == l);
			assert(to[i] <= high);
			if (to[i] <= mid) break;
			extracted.push_back(i);
			inds[l].pop_back();
		}
	}
	{
		// low, mid
		tt++, comps = 0;
		fixall(mid, mid);
		for (int i = mid - 1; i >= low; i--) {
			for (int r = 0; r < sz; r++) {
				if (a[r][i] == a[r][i + 1]) join(getid(r, i), getid(r, i + 1));
			}
			fixall(i, mid);
		}
	}
	{
		// mid + 1, high
		tt++, comps = 0;
		fixall(mid + 1, mid + 1);
		for (int i = mid + 2; i <= high; i++) {
			for (int r = 0; r < sz; r++) {
				if (a[r][i] == a[r][i - 1]) join(getid(r, i), getid(r, i - 1));
			}
			fixall(i, mid + 1);
		}
	}

	for (auto& i : extracted) {
		int l = from[i], r = to[i];
		tt++, comps = 0;
		for (int row = 0; row < sz; row++) {
			{
				int a = getid(row, l);
				if (last[a] < tt) {
					comps++;
					last[a] = tt;
					papa[a] = a;
				}

			}
			{
				int a = getid(row, r);
				if (last[a] < tt) {
					comps++;
					last[a] = tt;
					papa[a] = a;
				}
			}
		}
		for (int r1 = 0; r1 < sz; r1++) {
			for (int r2 = r1 + 1; r2 < sz; r2++) {
				if (chompy[r1][l] == chompy[r2][l]) join(getid(r1, l), getid(r2, l));
				if (chompy[r1][r] == chompy[r2][r]) join(getid(r1, r), getid(r2, r));
			}
		}
		comps = 0;
		for (int row = 0; row < sz; row++) {
			if (a[row][mid] == a[row][mid + 1]) {
				join(getid(row, l), getid(row, r));
			}
		}
		print[i] = king[l] + king[r] + comps;
	}

	rec(low, mid);
	rec(mid + 1, high);
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	cin >> sz >> n >> q;
	for (int i = 0; i < sz; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> from[i] >> to[i];
		print[i] = -1;
		inds[from[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		sort(inds[i].begin(), inds[i].end(), cmp_inds);
	}
	rec(1, n);
	for (int i = 1; i <= n; i++) {
		assert(inds[i].empty());
	}
	for (int i = 1; i <= q; i++) {
		cout << print[i] << "\n";
	}



}