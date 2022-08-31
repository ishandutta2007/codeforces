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

const int N = 3e5 + 10, B = 32;

struct Node {
	int ctr = 0, ch[2] = {0};
} block[N * B];

int root = 1, nxt = 2;
int a[N], p[N];

void trie_insert(int x);
int check_and_remove(int x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		trie_insert(p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << check_and_remove(a[i]) << ' ';
	}
}

void trie_insert(int x) {
	int cur = root;
	for (int i = B - 1; i >= 0; --i) {
		bool bit = x & (1 << i);
		if (block[cur].ch[bit] == 0) {
			block[cur].ch[bit] = nxt++;
		}
		cur = block[cur].ch[bit];
		++block[cur].ctr;
	}
}

int check_and_remove(int x) {
	int cur = root, ans = 0;
	for (int i = B - 1; i >= 0; --i) {
		bool bit = x & (1 << i);
		int good = block[cur].ch[bit];
		if (good and block[good].ctr) {
			cur = good;
		} else {
			ans |= (1 << i);
			cur = block[cur].ch[!bit];
		}
		--block[cur].ctr;
	}
	return ans;
}