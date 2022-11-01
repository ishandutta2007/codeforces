#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 1e6 + 7;

const int MOD[2] = {1000000007, 1000000009};
const int ANS_MOD = 1e9 + 7;

struct Hash {
	int v[2];
	Hash(int a = 0, int b = 0) {
		v[0] = a;
		v[1] = b;
	}
	void mul(const Hash &o) {
		for (int i = 0; i < 2; i++) {
			v[i] = 1LL * v[i] * o.v[i] % MOD[i];
		}
	}
	void add(const Hash &o) {
		for (int i = 0; i < 2; i++) {
			v[i] = (v[i] + o.v[i]) % MOD[i];
		}
	}
	friend bool operator <(const Hash &a, const Hash &b) {
		return a.v[0] != b.v[0] ? a.v[0] < b.v[0] : a.v[1] < b.v[1];
	}
	friend bool operator ==(const Hash &a, const Hash &b) {
		return a.v[0] == b.v[0] && a.v[1] == b.v[1];
	}
	void show() {
		printf("%d %d\n", v[0], v[1]);
	}
};

Hash val[N];
int n, m;
Hash global = Hash(1, 1);
Hash magic = Hash(10009, 10007);

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		val[i] = Hash(0, 0);
	}
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		static map<int, int> cnt;
		cnt.clear();
		for (int j = 0; j < num; j++) {
			int x;
			scanf("%d", &x);
			cnt[--x]++;
		}
		for (map<int, int> :: iterator it = cnt.begin(); it != cnt.end(); it++) {
			Hash tmp = global;
			tmp.mul(Hash(it->second, it->second));
			val[it->first].add(tmp);
		}
		global.mul(magic);
	}
	sort(val, val + m);
	int ans = 1;
	for (int i = 0, j; i < m; i = j) {
		for (j = i; j < m && val[j] == val[i]; j++);
		for (int k = 1; k <= j - i; k++) {
			ans = 1LL * k * ans % ANS_MOD;
		}
	}
	printf("%d\n", ans);
}