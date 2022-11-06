#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node{
	int son[26];
	vector<int>g;
}f[1000000];
int seg[4000000];
struct node1{
	int son[26];
	int fail, l, r;
	vector<int>g;
}tri[1000000];
int n, L;
int id[1000001], d[1000001];
int tot;
int head[1000001];
struct node2{
	int ans, id;
}q[1000001];
char s[1000001];
int Next[1000001];
int ins(int s, char*s1, int len, int l){
	if (l == len) {
		return s;
	}
	if (!tri[s].son[s1[l] - 'a']) 
		tri[s].son[s1[l] - 'a'] = ++ L;
	return ins(tri[s].son[s1[l] - 'a'], s1, len, l + 1);
}
void bfs(){
	int l = 0, r = 1;
	d[1] = 0;
	while (l < r) {
		++l;
		for (int i = 0; i < 26; i ++)
			if (tri[d[l]].son[i]) {
				int x  = tri[d[l]].fail;
				while (!tri[x].son[i] && x) x = tri[x].fail;
				d[++r] = tri[d[l]].son[i];
				if (tri[x].son[i] != d[r])
					tri[d[r]].fail = tri[x].son[i];
			}
	}
	for (int i = 1; i <= L ; i ++)
		tri[tri[i].fail].g.push_back(i);
}
void ins(int l, int r, int s, int ll, int v) {
	seg[s] += v;
	if (l == r) return;
	if ((l + r) /2 >= ll)
		ins(l, (l + r) /2, s + s, ll, v);
	else
		ins((l + r) / 2 + 1, r ,s + s +1, ll, v);
}
int get(int l, int r, int s, int ll, int rr){
	if (r < ll || rr < l ) return 0;
	if (ll <= l && r <= rr) return seg[s];
	return get(l, (l + r) / 2, s + s, ll, rr) + get((l+r)/ 2 + 1, r, s+ s+ 1, ll, rr);
	
}
void dfs(int x) {
	static int tot = 0;
	tri[x].l = ++tot;
	for (auto u:tri[x].g)
		dfs(u);
	tri[x].r = tot;
}
void dfs(int x, int y) {
	ins(1, L + 1, 1, tri[y].l, 1);
	for (auto u:f[x].g) {
		q[u].ans = get(1, L + 1 ,1, tri[q[u].id].l, tri[q[u].id].r);
	}
	for (int i = 0;i < 26; i ++)
		if (f[x].son[i]) {
			int z = y;
			while (z && !tri[z].son[i]) z = tri[z].fail;
			if (tri[z].son[i]) z = tri[z].son[i];
			dfs(f[x].son[i], z);
		}
	ins(1, L + 1, 1, tri[y].l, -1);
}
int main(){
	scanf("%d", &n);
	tot = 0;
	for (int i = 1; i <= n ; i ++) {
		int x;
		char c;
		scanf("%d", &x);
		if (x == 1) {
		
			scanf(" %c", &c);
			head[++head[0]] = ++tot;
			f[tot].son[c - 'a'] = tot + 1;
			++tot;
			id[i] = tot;
		} else {
			scanf("%d %c", &x, &c);
			if (!f[id[x]].son[c - 'a']) {
				f[id[x]].son[c - 'a'] = ++tot;
				id[i] = tot;
			} else 
				id[i] = f[id[x]].son[c - 'a'];
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m ; i ++)
	{
		int x;
		scanf("%d" , &x);
		scanf(" %s", s);
		f[id[x]].g.push_back(i);
		q[i].id = ins(0, s, strlen(s), 0);
	}
	bfs();
	dfs(0);
	for (int i = 1; i<= head[0]; i++)
		dfs(head[i], 0);
	for (int i = 1; i <= m ; i++)
		printf("%d\n", q[i].ans);
	return 0;
}