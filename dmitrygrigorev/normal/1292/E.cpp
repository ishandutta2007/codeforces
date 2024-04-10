#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<char> x = {'H', 'O', 'C'};

vector<int> ask(string t) {
	cout << "? " << t << endl;
	int k;
	cin >> k;
	if (k==-1) exit(0);
	vector<int> res(k);
	for (int i = 0; i < k; ++i) {
		cin >> res[i];
		res[i]--;
	}
	return res;
}

void restore(vector<char> &ans, int l, int r) {
	while (l > 0) {
		bool was = false;
		for (int j = 0; j < 2; ++j) {
			string Q = "";
			Q += x[j];
			for (int i = l; i <= r; ++i) {
				Q += ans[i];
			}
			vector<int> T = ask(Q);
			for (int e = 0; e < T.size(); ++e) {
				if (T[e] == l-1) {
					ans[l-1] = x[j];
					was = true;
				}
			}
		}
		if (!was) ans[l-1] = x[2];
		l--;
	}
	while (r+1 < ans.size()) {
		bool was = false;
		for (int j = 0; j < 2; ++j) {
			string Q = "";
			for (int i = l; i <= r; ++i) {
				Q += ans[i];
			}
			Q += x[j];
			vector<int> T = ask(Q);
			for (int e = 0; e < T.size(); ++e) {
				if (T[e] == l) {
					ans[r+1] = x[j];
					was = true;
				}
			}
		}
		if (!was) ans[r+1] = x[2];
		r++;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<char> ans(n, '0');

	vector<int> a = ask("HO");

	if (a.size()) {
		int P = a[0];
		ans[P] = 'H', ans[P+1] = 'O';
		restore(ans, P, P+1);
		cout << "! ";
		for (int i = 0; i < ans.size(); ++i) cout << ans[i];
		cout << endl;
		int s;
	cin >> s;
		return;
	}

	a = ask("HC");

	if (a.size()) {
		int P = a[0];
		ans[P] = 'H', ans[P+1] = 'C';
		restore(ans, P, P+1);
		cout << "! ";
		for (int i = 0; i < ans.size(); ++i) cout << ans[i];
		cout << endl;
		int s;
	cin >> s;
		return;
	}

	vector<int> b = ask("OC");
	vector<int> c = ask("CO");

	if (b.size() > 0 || c.size() > 0) {
		for (int i = 0; i < b.size(); ++i) {
			ans[b[i]] = 'O';
			ans[b[i]+1] = 'C';
		}
		for (int i = 0; i < c.size(); ++i) {
			ans[c[i]] = 'C';
			ans[c[i]+1] = 'O';
		}

		while (true) { //OCOOH
			bool was = false;
			for (int i = 0; i < n; ++i) {
				if (ans[i] == '0') {
					if (i + 1 < n && ans[i+1] != '0') {
						ans[i] = ans[i+1];
						was = true;
					}
					if (i - 1 >= 0 && ans[i-1] != '0') {
						ans[i] = ans[i-1];
						was = true;
					}
				}
			}
			if (!was) break;
		}

		string t = "";
		t += ans[n-1];
		t += ans[n-1];

		vector<int> Q = ask(t);
		set<int> sas;
		for (int i = 0; i < Q.size(); ++i) sas.insert(Q[i]);
		for (int i = n-1; i >= 0; i--) {
			if (ans[i-1] != t[0]) break;
			if (!sas.count(i-1)) ans[i] = 'H';
			else break;
		}
	}

	else{
		vector<int> a = ask("HHH");
		if (a.size()) {
			for (int i = 0; i < a.size() + 2; ++i) {
				ans[n-i-1] = 'H';
			}
			vector<int> b = ask("OHH");
			if (b.size()) {
				for (int i = 0; i < n; ++i) if (ans[i] == '0') ans[i] = 'O';
			}
			else{
				for (int i = 0; i < n; ++i) if (ans[i] == '0') ans[i] = 'C';
			}
		}
		else{
			a = ask("OOO");
			if (a.size()) {
				for (int i = 0; i < n; ++i) {
					if (i < a.size() + 2) ans[i] = 'O';
					else ans[i] = 'H';
				}
			}
			else{
				a = ask("CCC");
				if (a.size()) {
					for (int i = 0; i < n; ++i) {
						if (i < a.size() + 2) ans[i] = 'C';
						else ans[i] = 'H';
					}
				}
				else{
					a = ask("CCHH");
					if (a.size()) {
						ans[0] = 'C', ans[1] = 'C', ans[2] = 'H', ans[3] = 'H';
					}
					else{
						ans[0] = 'O', ans[1] = 'O', ans[2] = 'H', ans[3] = 'H';
					}
				}
			}
		}
	}

	cout << "! ";
	for (int i = 0; i < ans.size(); ++i) cout << ans[i];
	cout << endl;

	int s;
	cin >> s;






}

int main(){
#ifdef LOCAL
	//freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}