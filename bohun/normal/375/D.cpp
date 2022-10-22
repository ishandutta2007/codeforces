#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;

const int nax = 1e5 + 111;
const int P = 400;

int n, m;
int col[nax];
int a, b;
vector <int> v[nax];
int in[nax], out[nax], timer = 1;
int ord[nax];

struct query {
	int l, r, k, id;
};

vector <query> Q;

void dfs(int u, int p) {
	ord[timer] = col[u];
	in[u] = timer++;
	
	for(auto it : v[u])
		if(it != p)
			dfs(it, u);
	
	out[u] = timer;
}

int ans[nax];
int suf[nax];
int ile[nax];

void add(int kol) {
	ile[kol] += 1;
	suf[ile[kol]] += 1;
}

void del(int kol) {
	suf[ile[kol]] -= 1;
	ile[kol] -= 1;
}

void br(int ind, int u, int k) {
	int L = in[u];
	int R = out[u] - 1;
	FOR(i, L, R)
		add(ord[i]);
	ans[ind] = suf[k];
	FOR(i, L, R)
		del(ord[i]);
}
	

int main() {		
	scanf("%d %d", &n, &m);
	FOR(i, 1, n)
		scanf("%d", col + i);
	FOR(i, 1, n - 1) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1, 0);
	
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		query x = {in[a], out[a] - 1, b, i};
		if(in[a] / P == (out[a] - 1) / P)
			br(i, a, b);
		else {
			Q.pb(x);
		}
	}
	sort(Q.begin(), Q.end(), [](query a, query b) {
		if(a.l / P != b.l / P)
			return a.l / P < b.l / P;
		return a.r < b.r;
	});
	
	int L = 1;
	int R = 0;
	for(auto it : Q) {
		int left = it.l;
		int right = it.r;
		while(right > R)
			add(ord[++R]);
		while(left < L)
			add(ord[--L]);
		while(right < R)
			del(ord[R--]);
		while(L < left)
			del(ord[L++]);
		ans[it.id] = suf[it.k];
	}
	FOR(i, 1, m)
		printf("%d\n", ans[i]);
		
		
				
			
	
	return 0;
}