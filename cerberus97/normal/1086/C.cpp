/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10, K = 30;

int out[K], in[K];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int k; string s, a, b;
		cin >> k >> s >> a >> b;
		int n = a.size();
		for (int i = 0; i < k; ++i) {
			in[i] = out[i] = -1;
		}
		// int lo = 1, hi = n;
		// string test;
		// bool done = false;
		// while (lo <= hi) {
		// int mid = (lo + hi) / 2;
		// cout << "mid " << mid << endl;
		// bool ok = true;
		int p = 0;
		for (int i = 0; i < n; ++i) {
			int u = s[i] - 'a';
			int v = a[i] - 'a';
			if (out[u] != -1 and out[u] != v) {
				break;
			}
			if (in[v] != -1 and in[v] != u) {
				break;
			}
			out[u] = v;
			in[v] = u;
			if (i == n - 1) {
				p = n;
				break;
			}
			u = s[i + 1] - 'a';
			v = a[i + 1] - 'a';
			if (out[u] == -1) {
				for (int j = v + 1; j < k; ++j) {
					if (in[j] == -1) {
						p = i + 1;
						break;
					}
				}
			} else if (out[u] > v) {
				p = i + 1;
			}
		}
		// cout << p << endl;
		for (int i = 0; i < k; ++i) {
			in[i] = out[i] = -1;
		}
		for (int i = 0; i < p; ++i) {
			int u = s[i] - 'a';
			int v = a[i] - 'a';
			out[u] = v;
			in[v] = u;
		}
		if (p < n) {
			int u = s[p] - 'a';
			int x = a[p] - 'a';
			if (out[u] == -1) {
				for (int v = x + 1; v < k; ++v) {
					if (in[v] == -1) {
						in[v] = u;
						out[u] = v;
						break;
					}
				}
			}
		}
		for (int i = p + 1; i < n; ++i) {
			int u = s[i] - 'a';
			if (out[u] == -1) {
				for (int v = 0; v < k; ++v) {
					if (in[v] == -1) {
						in[v] = u;
						out[u] = v;
						break;
					}
				}
			}
		}
		for (int u = 0; u < k; ++u) {
			if (out[u] == -1) {
				for (int v = 0; v < k; ++v) {
					if (in[v] == -1) {
						in[v] = u;
						out[u] = v;
						break;
					}
				}
			}	
		}
		string test = s;
		for (auto &i : test) {
			i = char(out[i - 'a'] + 'a');
		}
		// cout << test << endl;
		if (a <= test and test <= b) {
			cout << "YES\n";
			for (int i = 0; i < k; ++i) {
				cout << char(out[i] + 'a');
			}
			cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
}