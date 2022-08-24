#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int g1 = -1, g2 = -1;

int gcd(int x, int y) {
	if (y==0) return x;
	return gcd(y, x%y);
}

pair<int, int> transform(int x, int y) {

	int G = gcd(x, y);
	x /= G;
	y /= G;

	if (g1 == -1) g1 = abs(G);
	else g2 = abs(G);

	if (x < 0) {
		x *= -1, y *= -1;
	}
	else if (x == 0 && y < 0) y *= -1;
	return mp(x, y);

}

struct Line {
	int a;
	int b; 
	int c;

	void construct(int px, int py, int qx, int qy) {
		a = py - qy;
		b = qx - px;
		c = -a * px - b*py;
	}

	int upd(int x, int& l, int& r) {
		return (-c - a*x) / b;

	}

};

main(){
#ifdef LOCAL
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	if (a == 0) {
		swap(a, c);
		swap(b, d);
	}

	if (a == 0 && b == 0) {
		cout << "NO\n";
		return 0;
	}

	if (c == 0 && d == 0) {
		cout << "NO\n";
		return 0;
	}

	auto A = transform(a, b), B = transform(c, d);
	if (A.x == B.x && A.y == B.y) {
		cout << "NO\n";
		return 0;
	}

	B = mp(c, d);

	Line first, second;
	first.construct(0, 0, A.x, A.y);
	second.construct(B.x, B.y, A.x+B.x, A.y+B.y);

	vector<pair<int, int> > ans;
	ans.pb(mp(0, 0));

	for (int i = 0; i < A.x; ++i) {
		int L = -1e18, R = 1e18;
		int ww = first.upd(i, L, R);
		int qq = second.upd(i, L, R);

		L = min(ww, qq) - 2, R = max(ww, qq) + 2;

		for (int j = L; j <= R; ++j) {
			int W1 = first.a * i + first.b * j + first.c;
			int W2 = second.a * i + second.b * j + second.c;

			if (W1 > 0 && W2 < 0) {
				ans.pb(mp(i, j));
			}
			else if (W1 < 0 && W2 > 0) {
				ans.pb(mp(i, j));
			}

			if (ans.size() > n) {
				cout << "NO\n";
				exit(0);
			}

		}

	}

	if (ans.size()*g1 != n) {
		cout << "NO\n";
		exit(0);
	} 

	cout << "YES\n";
	for (auto x : ans) {
		for (int i = 0; i < g1; ++i) {
			for (int j = 0; j < 1; ++j) {
				cout << x.x + i*A.x + j*B.x << " " << x.y+i*A.y+j*B.y << endl;
			}
		}
	}


}