#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int matrix[257][257];
int ans[257][257];

int n, m;

bool bad(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return (ans[x][y] == -1);
}

int code(tuple<int, int, int> a) {
	int x = get<0>(a), y = get<1>(a);
	if (get<2>(a) == 0) {
		int ans = (int) bad(x+1, y) +  (int) bad(x, y-1);
		return ans;
	}
	int ans = (int) bad(x-1, y) + (int) bad(x, y+1);
	return ans;
}

struct lex_compare {
    bool operator() (const tuple<int, int, int> & lhs, const tuple<int, int, int> & rhs) const {
        int a = code(lhs);
        int b = code(rhs);
        if (a != b) return (a < b);

        if (get<0>(lhs) != get<0>(rhs)) return (get<0>(lhs) < get<0>(rhs));
        if (get<1>(lhs) != get<1>(rhs)) return (get<1>(lhs) < get<1>(rhs));
        if (get<2>(lhs) != get<2>(rhs)) return (get<2>(lhs) < get<2>(rhs));

        return false;
    }
};

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
			matrix[i][j]--;
			ans[i][j] = -1;
		}
	}

	int a = n-1, b = m-1;
	set<tuple<int, int, int>, lex_compare> ms;

	vector<int> mxa(n, -1);
	vector<int> mxb(m, -1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			mxa[i] = max(mxa[i], matrix[i][j]);
			mxb[j] = max(mxb[j], matrix[i][j]);
		}
	}

	for (int i = n*m-1; i >= 0; i--) {
		bool A = false, B = false;
		for (int j = 0; j < n; ++j) if (mxa[j] == i) A = true;
		for (int j = 0; j < m; ++j) if (mxb[j] == i) B = true;

		if (!A && !B) {

			auto it = ms.begin();
			auto p = (*it);

			int X = get<0>(p), Y = get<1>(p);

			vector<tuple<int, int, int> > deleted;

			for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
				if (abs(dx) + abs(dy) > 1) continue;
				for (int e = 0; e < 2; ++e) {
					if (ms.count(make_tuple(X+dx, Y+dy, e))) {
						if (abs(dx) + abs(dy) == 1) deleted.pb(make_tuple(X+dx, Y+dy, e));
						ms.erase(ms.find(make_tuple(X+dx, Y+dy, e)));
					}
				}
			}

			ans[X][Y] = i;
			for (auto t : deleted) {
				ms.insert(t);
			}
		}

		else if (A && B) {
			ans[a][b] = i;
			for (int j = b+1; j < m; ++j) ms.insert(make_tuple(a, j, 0));
			for (int j = a+1; j < n; ++j) ms.insert(make_tuple(j, b, 1));
			a--, b--;
		}

		else if (A) {
			ans[a--][b+1] = i;
			for (int j = b+2; j < m; ++j) ms.insert(make_tuple(a+1, j, 0));
		}

		else if (B) {
			ans[a+1][b--] = i;
			for (int j = a+2; j < n; ++j) ms.insert(make_tuple(j, b+1, 1));
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cout << ans[i][j] + 1 << " ";
		cout << "\n";
	}





}