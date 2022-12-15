#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
int fa[500005]; bool flg[500005];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

vector<int> V[500005];
//bool cmp(const vector<int> a, const vector<int> b) {
//	if(a[0] != b[0]) return a[0] < b[0];
//	if(!a.size()) return 1;
//	if(!b.size()) return 0;
//	return a[1] < b[1];
//}
int ANS[500005]; int cnt;

const int p = 1000000007;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		fa[i] = i;
	for(int i = 1; i <= n; i++) {
		int len; scanf("%d", &len);
		V[i].resize(len);
		for(int j = 0; j < len; j++) scanf("%d", &V[i][j]);
	}
//	sort(V + 1, V + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		if(V[i].size() == 2) {
			int x = find(V[i][0]), y = find(V[i][1]);
			if(x == y || (flg[x] & flg[y])) continue;
			else fa[x] = y, flg[y] |= flg[x], ANS[++cnt] = i;
		}
		else {
			int x = find(V[i][0]);
			if(flg[x]) continue;
			flg[x] = 1, ANS[++cnt] = i;
		}
	}
	
	int T = 1;
	for(int i = 1; i <= cnt; i++) T <<= 1, T %= p;
	printf("%d %d\n", T, cnt);
	for(int i = 1; i <= cnt; i++) {
		printf("%d ", ANS[i]);
	}
}