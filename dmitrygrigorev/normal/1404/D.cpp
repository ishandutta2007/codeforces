#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void change(vector<bool> &used, int i, int n) {
	if (i >= n/2) i -= n/2;
	used[i] = true;
	used[i + n/2] = true; 
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << "First" << endl;
		for (int i = 0; i < n; ++i) cout << i+1 << " ";
		for (int i = 0; i < n; ++i) cout << i+1 << " ";
		cout << endl;

		int x;
		cin >> x;

		exit(0);

	}

	cout << "Second" << endl;
	n *= 2;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i]--;
	}

	vector<int> take;

	vector<pair<int, int> > kek(n/2, mp(-1, -1));
	for (int i = 0; i < n; ++i) {
		if (kek[v[i]].x == -1) kek[v[i]].x = i;
		else kek[v[i]].y = i;
	}

	vector<bool> used(n, false);
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		change(used, i, n);

		take.pb(i);
		int cur_pair = v[i];
		int last = i;

		while (true) {
			int now = kek[cur_pair].x;
			if (now == last) now = kek[cur_pair].y;

			if (used[now]) break;
			int Q = now - n/2;
			if (Q < 0) Q = now + n/2;

			take.pb(Q);
			change(used, Q, n);

			cur_pair = v[Q];
			last = Q;
		}
	}

	assert(take.size() == n/2);
	ll sum = 0;

	for (auto x : take) sum += (x + 1);

	if (sum % n != 0) {
		for (auto &x : take) {
			if (x < n/2) x += n/2;
			else x -= n/2;
		}
	}

	for (auto x : take) cout << x+1 << " ";
	cout << endl;

	int t;
	cin >> t;

}