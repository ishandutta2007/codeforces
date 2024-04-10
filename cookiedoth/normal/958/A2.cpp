/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

int in(vector<int> a, vector<int> b) {
	int n = a.size(), m = b.size();
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		v.push_back(a[i]);
	}
	v.push_back(-2);
	for (int i = 0; i < m; ++i) {
		v.push_back(b[i]);
	}
	int s = n + m + 1;
	vector<int> pref(s);
	for (int i = 1; i < s; ++i) {
		int cur_pref = pref[i - 1];
		while (cur_pref > 0 && v[cur_pref] != v[i]) {
			cur_pref = pref[cur_pref - 1];
		}
		if (v[cur_pref] == v[i])
			pref[i] = cur_pref + 1;
		else
			pref[i] = cur_pref;
	}
	for (int i = 2 * n; i < s; ++i) {
		if (pref[i] == n)
			return i - 2 * n;
	}
	return -1;
}

const ll MOD = 1e9 + 7;
const int mx = 2018;
const int mx2 = 228;
const int bmx = 5e5;
const int K = 26;

int n, m, a[mx][mx2], b[mx2][mx], h[mx], h1[mx2][mx], ptr = 1, go[bmx][K], term[bmx];

void init() {
	for (int i = 0; i < bmx; ++i) {
		for (int j = 0; j < K; ++j) {
			go[i][j] = -1;
		}
		term[i] = -1;
	}
}

int add_a_string(int pos) {
	int v = 0;
	for (int i = 0; i < m; ++i) {
		int s = a[pos][i];
		if (go[v][s] == -1) {
			go[v][s] = ptr;
			v = ptr;
			ptr++;
		}
		else {
			v = go[v][s];
		}
	}
	if (term[v] == -1) {
		term[v] = pos;
		return pos;
	}
	else {
		return term[v];
	}
}

int get_b_string(int pos_i, int pos_j) {
	int v = 0;
	for (int i = 0; i < m; ++i) {
		int s = b[pos_i][pos_j + i];
		if (go[v][s] == -1) {
			return -1;
		}
		else {
			v = go[v][s];
		}
	}
	return term[v];
}

void check_in() {
	vector<int> a = {2, 3, 3};
	vector<int> b = {3, 2, 3, 2, 3, 4, 2, 3, 3, 3, 2, 3, 1};
	cout << in(a, b) << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = (c - 'a');
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			b[i][j] = (c - 'a');
		}
	}
	init();
	for (int i = 0; i < n; ++i) {
		h[i] = add_a_string(i);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n - m; ++j) {
			h1[i][j] = get_b_string(i, j);
		}
	}
	/*cout << "hash" << endl;
	for (int i = 0; i < n; ++i) {
		cout << h[i] << " ";
	}
	cout << endl;
	cout << "hash1" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n - m; ++j) {
			cout << h1[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<int> defalut;
	for (int i = 0; i < n; ++i) {
		defalut.push_back(h[i]);
	}
	for (int i = 0; i <= n - m; ++i) {
		vector<int> cur;
		for (int j = 0; j < m; ++j) {
			cur.push_back(h1[j][i]);
		}
		int res = in(cur, defalut);
		if (res != -1) {
			cout << res + 1 << " " << i + 1 << endl;
			return 0;
		}
	}
}