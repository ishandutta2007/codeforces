#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;
const int mx = 4e5;
const int bmx = 6e6;
const int lg = 31;

int sz[bmx], go[bmx][2], ptr = 1;

void init() {
	for (int i = 0; i < bmx; ++i) {
		go[i][0] = -1;
		go[i][1] = -1;
	}
}

void add_number(int x) {
	//cout << "adding number " << x << endl;
	int v = 0;
	sz[v]++;
	for (int i = lg - 1; i >= 0; --i) {
		int c = ((x >> i) & 1);
		//cout << "c = " << c << endl;
		if (go[v][c] == -1) {
			go[v][c] = ptr;
			//cout << "go " << v << " " << c << " is " << ptr << endl;
			v = ptr;
			ptr++;
			//cout << "creating new vertex " << ptr - 1 << endl;
			//cout << "v = " << ptr - 1 << endl;
		}
		else {
			v = go[v][c];
			//cout << "v = " << v << endl;
		}
		sz[v]++;
	}
}

void erase_number(int x) {
	int v = 0;
	sz[v]--;
	for (int i = lg - 1; i >= 0; --i) {
		int c = ((x >> i) & 1);
		v = go[v][c];
		sz[v]--;
		//cout << "sz " << v << " --" << endl;
	}
}

int get_sz(int v) {
	if (v == -1)
		return 0;
	else
		return sz[v];
}

void print_trie() {
	cout << "trie" << endl;
	for (int i = 0; i < 30; ++i) {
		cout << go[i][0] << " " << go[i][1] << endl;
	}
	cout << "/trie" << endl;
}

int get_min(int x) {
	//cout << "getting min of " << x << endl;
	int v = 0, res = 0;
	for (int i = lg - 1; i >= 0; --i) {
		//cout << "bit = " << (1 << i) << endl;
		//cout << "sz[v] = " << sz[v] << endl;
		int c = ((x >> i) & 1);
		//cout << "c = " << c << endl;
		//cout << "checking sz of " << go[v][c] << endl;
		if (get_sz(go[v][c]) > 0) {
			v = go[v][c];
		}
		else {
			v = go[v][c ^ 1];
			res += (1 << i);
		}
		//cout << "res = " << res << endl;
		//cout << "v = " << v << endl;
	}
	return res;
}

int get_min_and_erase(int x) {
	int res = get_min(x);
	erase_number(x ^ res);
	return res;
}

int a[mx], b[mx], n, ans[mx];

int main() {
	init();
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		add_number(b[i]);
	}
	//cout << "go 0 1 is " << go[0][1] << endl;
	//print_trie();
	for (int i = 0; i < n; ++i) {
		ans[i] = get_min_and_erase(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}