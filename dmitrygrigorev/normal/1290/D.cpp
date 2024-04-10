#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<bool> good;
int n, k;

char R = 'R';

bool ask(int x) {
	cout << "? " << x+1 << endl;
	char ch;
	cin >> ch;
	return (ch == 'Y');
}

void solve(int l, int r) {
	if (r - l == k) {
		cout << R << endl;
		for (int i = l; i < r; ++i) {
			bool res = ask(i);
			if (res) good[i] = false;
		}
		return;
	}

	int mid = (l+r)/2;
	solve(l, mid);
	solve(mid, r);

	if (k == 1) {
		for (int i = mid; i < r; ++i) {
			for (int j = l; j < mid; ++j) {
				cout << R << endl;
				ask(j);
				bool res = ask(i);
				if (res) good[i] = false;
			}
		}
		return;
	}

	for (int i = mid; i < r; i += k/2) {
		for (int j = l; j < mid; j += k) {
			cout << R << endl;
			for (int e = 0; e < k/2; ++e) {
				if (good[j+e]) ask(j+e);
			}
			for (int e = 0; e < k/2; ++e) {
				if (good[i+e]) {
					bool res = ask(i+e);
					if (res) good[i+e] = false;
				}
			}
			for (int e = 0; e < k/2; ++e) {
				bool res = ask(j+k/2+e);
				if (res) good[j+k/2+e] = false;
			}
		}
	}

}

int main(){
#ifdef LOCAL
	//freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;


	cout << R << endl;

	good.assign(n, true);

	solve(0, n);

	int ans = 0;
	for (int i = 0; i < n; ++i) if (good[i]) ans++;
	cout << "! " << ans << endl;

}