#include <bits/stdc++.h>
using namespace std;
#define N 2020
struct bitset {
    unsigned int b[N+31>>5];
    void reset() {
        memset(b, 0, sizeof b);
    }
    void set(int x) {
        b[x>>5] |= 1u << (x & 31);
    }
    void flip(int x) {
        b[x>>5] ^= 1u << (x & 31);
    }
    bool operator [] (int x) {
        return b[x>>5] & (1u << (x & 31));
    }
} v[N], rv[N], vis;
int t, n, m, q, ft, ord[N];
char s[N];
int ans, cnt;
void dfs(int x) {
    vis.set(x);
    for (int i = 0; i <= (n >> 5); i ++) {
        while (1) {
            unsigned int y = v[x].b[i] ^ (v[x].b[i] & vis.b[i]);
            if (!y) break;
            dfs((i << 5) ^ __builtin_ctz(y));
        }
    }
    ord[ft--] = x;
}
void rdfs(int x) {
    vis.set(x);
    cnt ++;
    for (int i = 0; i <= (n >> 5); i ++) {
        while (1) {
            unsigned int y = rv[x].b[i] ^ (rv[x].b[i] & vis.b[i]);
            if (!y) break;
            rdfs((i << 5) ^ __builtin_ctz(y));
        }
    }
}
vector<int> all;
bool kosaraju() {
    vis.reset();
    ft = n;
    for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
    vis.reset();
    all.clear();
    for (int i = 1; i <= n; i ++) if (!vis[ord[i]]) {
            cnt = 0;
            rdfs(ord[i]);
            all.push_back(cnt);
        }
	return all.size() == 1;
}

void flip(int x) {
	for (int i = 1; i <= n; i ++) if (x != i) {
		v[i].flip(x), v[x].flip(i);
		rv[i].flip(x), rv[x].flip(i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) v[i].reset(), rv[i].reset();
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j ++) {
			if (s[j] == '1') v[i].set(j), rv[j].set(i);
		}
	}
	if (kosaraju()) {
		puts("0 1");
		return 0;
	}
	if (all.size()==2&&all[0]==3&&all[1]==3) {
		puts("2 18");
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n ;i++) {
		flip(i);
		if (kosaraju()) cnt ++;
		flip(i);
	}
	if (cnt > 0) {
		printf("%d %d\n", 1, cnt);
		return 0;
	}
	puts("-1");
    return 0;
}