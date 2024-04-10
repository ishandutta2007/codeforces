#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
#define randbit() (rand() >> 3 & 1)

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char tp[100005];
int e0[100005], e1[100005];
bool op0[100005], op1[100005];
vector<int> G[200005];
int ret[100005];
bool ans;

void add_edge(int u, int v)
{
	G[u].push_back(v ^ 1);
	G[v].push_back(u ^ 1);
}

vector<int> hv, rhv;
bool vis[100005];
int dfs(int cur, bool clr)
{
	int cv = cur >> 1, col = cur & 1;
	if(ret[cv] == (col ^ 1)) return -1;
	if(vis[cv]) return 0;
	if(ret[cv] != -1) return 0;
	
	hv.push_back(cv);
	if(ret[cv] == -1) rhv.push_back(cv);
	vis[cv] = true;
	ret[cv] = col;
	
	int res = tp[cv] == 'A';
	rep(i, G[cur].size()) {
		int ca = dfs(G[cur][i], clr);
		if(ca == -1) return -1;
		res += ca;
	}
	return res;
}

bool check(int x, int col, int ndv, bool clr)
{
	int res = dfs(x << 1 | col, clr);
	rep(i, hv.size()) vis[hv[i]] = false;
	hv.clear();
	if(clr) rep(i, rhv.size()) ret[rhv[i]] = -1;
	rhv.clear();
	return res == ndv;
}

void solve_d()
{
    srand(time(0));
	
	for(int i = 2; i < 2 * n + 2; i ++) G[i].clear();
	rep1(i, n) ret[i] = -1;
	
	rep(i, m) add_edge(e0[i] << 1 | op0[i], e1[i] << 1 | op1[i]);
	
	rep1(i, n) if(tp[i] == 'A') {
	    if(!check(i, 0, 1, true) || !check(i, 1, 1, true)) {
	        ans = false;
	        return;
	    }
	    check(i, randbit(), 1, false);
	} else {
	    if(check(i, 0, 0, true)) {
	        check(i, 0, 0, false);
	        continue;
	    } else if(check(i, 1, 0, true)) {
	        check(i, 1, 0, false);
	        continue;
	    }
	    ans = false;
	    return;
	}
	ans = true;
}

void input_d()
{
	scanf("%d%d%s", &n, &m, tp + 1);
	rep(i, m) {
		scanf("%d%d", &e0[i], &e1[i]);
		if(e0[i] < 0) {
			e0[i] *= -1;
			op0[i] = true;
		} else op0[i] = false;
		if(e1[i] < 0) {
			e1[i] *= -1;
			op1[i] = true;
		} else op1[i] = false;
	}
}

void output_d()
{
	printf(ans ? "TRUE\n" : "FALSE\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) {
		input_d();
		solve_d();
		output_d();
	}
	return 0;
}