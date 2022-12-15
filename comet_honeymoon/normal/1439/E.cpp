#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 800005;
int H(int x) {
	if (x == 0) return -1;
	return 31 - __builtin_clz(x);
}

struct node{ int x, y; };
int dep(node x) { return x.x | x.y; }
node fa(node x) {
	if (x.x == 0 && x.y == 0) return x;
	int i = __builtin_ctz(x.x | x.y);
	if (x.x >> i & 1) { x.x--; return x; }
	if (x.y >> i & 1) { x.y--; return x; }
}
bool operator < (const node u, const node v) {
	return u.x < v.x || (u.x == v.x && u.y < v.y);
}
bool DFN_cmp(const node u, const node v) {
	int dx = u.x ^ v.x, dy = u.y ^ v.y;
	if(dx == 0 && dy == 0) return 0;
	int i = H(dx | dy);
	int tu = u.x | u.y, tv = v.x | v.y;
	if ((tu >> i & 1) && (tv >> i & 1)) return (u.x >> i & 1) > (v.x >> i & 1);
	if (tu >> i & 1) return u.x >> i & 1;
	if (tv >> i & 1) return !(v.x >> i & 1);
	return 0;
}
node LCA(node u , node v) {
	node ans = (node){0 , 0};
	int tu = u.x | u.y, tv = v.x | v.y;
	while (1) {
		int iu = H(tu), iv = H(tv);
		if (iu == -1 || iv == -1) break;
		bool fu = u.x >> iu & 1, fv = v.x >> iv & 1;
		if(fu != fv) break;
		int mi = min(iu, iv); (fu ? ans.x : ans.y) |= 1 << mi;
		if (mi == iu) tu ^= 1 << iu;
		if (mi == iv) tv ^= 1 << iv;
	}
	return ans;
}
 
map<node, int> hsh; int tot;
node rhsh[maxn];
int id(node x) {
	if (!hsh.count(x)) { hsh[x] = ++tot; rhsh[tot] = x; }
	return hsh[x];
}

vector<int> G[maxn];
int C[maxn];
set<int> ans;
void insS(int x) {
	// printf("%d\n", x);
	if (!ans.count(x)) ans.insert(x);
	else ans.erase(x);
}
void dfs(int x, int fa) {
	for (int y : G[x]) dfs(y, x), C[x] += C[y];
	if (C[x])
		if (!fa) { insS(1); insS(2); }
		else { insS(dep(rhsh[fa]) + 2); insS(dep(rhsh[x]) + 2); }
}

node stk[maxn]; int len;
int main(){
	int n;
	scanf("%d", &n);
	
	vector<node> lis;
	for (int i = 1; i <= n; i++) {
		node u, v; scanf("%d%d%d%d", &u.x, &u.y, &v.x, &v.y);
		lis.push_back(u); lis.push_back(v);
		++C[id(u)]; ++C[id(v)];
		node lca = LCA(u, v);
		lis.push_back(lca); lis.push_back(fa(lca));
		--C[id(lca)];
		if(lca.x | lca.y) --C[id(fa(lca))];
	}
	sort(lis.begin(), lis.end(), DFN_cmp);

	for(node t : lis) {
		if (len) {
			node lca = LCA(stk[len], t);
			int lst = 0;
			while (len && dep(lca) <= dep(stk[len])) {
				if(lst) G[id(stk[len])].push_back(lst);
				lst = id(stk[len--]);
			}
			if (lst && id(lca) != lst) G[id(lca)].push_back(lst);
			stk[++len] = lca;
		}
		if (!len || id(stk[len]) != id(t)) stk[++len] = t;
	}
	// for (int i = 1; i <= len; i++) printf("%d %d\n", stk[i].x, stk[i].y);
	while (len >= 2)
		G[id(stk[len - 1])].push_back(id(stk[len])),
		len--;
	dfs(id(stk[1]), 0);
	
	int ANS = ans.size();
	printf("%d\n", ANS + (ANS & 1) - (ANS && *ans.begin() == 1));
}