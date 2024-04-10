#include <bits/stdc++.h>

using namespace std;

const int mx = 1e6;
const int K = 26;

int go[mx][K], sum[mx], term[mx], ptr = 1;

int ans = 0;

set<string> diff;

int add_string(string s) {
	int n = s.size();
	int v = 0;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		if (go[v][c] == -1) {
			go[v][c] = ptr;
			v = ptr;
			ptr++;
		}
		else {
			v = go[v][c];
		}
		a.push_back(v);
	}
	int d = 0;
	for (int i = 0; i < n; ++i) {
		if (sum[a[i]] == 1)
			d++;
	}
	/*cout << s << endl;
	for (int i = 0; i < n; ++i) {
		cout << sum[a[i]] <<  " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;*/
	if (d > 0) {
		for (int i = n - 1; i >= 0; --i) {
			if (sum[a[i]] == 1 && term[a[i]] == 0) {
				//cout << "i = " << i << endl;
				//cout << "fail " << a[i] << endl;
				d = 0;
				break;
			}
			if (sum[a[i]] == 1 && term[a[i]] == 1)
				break;
		}
	}
	//cout << "d = " << d << endl;
	if (diff.find(s) == diff.end()) {
		for (auto x : a) {
			sum[x]++;
		}
		diff.insert(s);
	}
	term[v] = 1;
	//cout << "term[" << v << "] = 1" << endl;
	if (d >= 3) {
		//cout << s << endl;
		//cout << "d = " << d << endl;
		//cout << n - d + 2 << endl;
		return n - d + 2;
	}
	else
		return n;
}

void init() {
	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < K; ++j) {
			go[i][j] = -1;
		}
	}
}

void parse(string s) {
	int n = s.size();
	string word = "";
	for (int i = 0; i < n; ++i) {
		if ('a' <= s[i] && s[i] <= 'z') {
			word.push_back(s[i]);
		}
		else {
			if (word != "")
				ans += add_string(word);
			word = "";
			ans++;
		}
	}
	if (word != "")
		ans += add_string(word);
}

int main() {
	init();
	string s;
	while (getline(cin, s)) {
		//if (s == "kek228")
		//	break;
		parse(s);
		ans++;
	}
	cout << ans << endl;
}