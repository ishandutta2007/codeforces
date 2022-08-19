#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, tp[300005];
char S[300005];
int to[300005];
vector<int> sta;
vector<int> T[300005];

int siz[300005];
void dfs0(int v)
{
	siz[v] = 1; tp[v] = 2;
	rep(i, T[v].size()) {
		int u = T[v][i];
		dfs0(u); siz[v] += siz[u];
	}
}
void dfs1(int v)
{
	rep(i, T[v].size()) {
		int u = T[v][i];
		tp[u] &= tp[v]; dfs1(u);
	}
}

int seq[2][300005], tot[2];
void calc(int v, int l, int id)
{
	if(tot[id] == l) return;
	seq[id][tot[id] ++] = 0;
	rep(i, T[v].size()) {
		int u = T[v][i];
		calc(u, l, id);
		if(tot[id] == l) return;
	}
	if(tot[id] == l) return;
	seq[id][tot[id] ++] = 1;
}
bool cmp(int x, int y)
{
	int len = min(siz[x], siz[y]) * 2;
	tot[0] = tot[1] = 0;
	calc(x, len, 0);
	calc(y, len, 1);
	rep(i, min(tot[0], tot[1])) if(seq[0][i] != seq[1][i]) return seq[0][i] < seq[1][i];
	return true;
}
vector<int> R;
void dfs2(int v)
{
	rep(i, T[v].size()) dfs2(T[v][i]);
	int mx = -1;
	R.clear();
	for(int i = (int)T[v].size() - 1; i >= 0; i --) {
		int u = T[v][i];
		if(mx == -1 || cmp(u, mx)) {
			R.push_back(u); mx = u;
		} else {
			tp[u] = 0; dfs1(u);
		}
	}
	reverse(R.begin(), R.end());
	T[v] = R;
}
void solve(int v)
{
	dfs0(v);
	dfs2(v);
}

int main()
{
	scanf("%s", S);
	n = strlen(S);
	
	int ed = -1;
	rep(i, n) {
		if(S[i] == '(') {
			if(!sta.empty()) T[sta.back()].push_back(i);
			else tp[i] = 1;
			sta.push_back(i);
		} else if(!sta.empty()) {
			to[i] = sta.back(); sta.pop_back();
		} else {
			ed = i; tp[i] = 2;
		}
	}
	rep(i, sta.size()) tp[sta[i]] = 2;
	
	int mx = -1;
	for(int i = ed - 1; i >= 0; i --) if(tp[i] == 2) mx = -1;
	else if(tp[i] == 1) {
		solve(i);
		if(mx != -1 && !cmp(i, mx)) {
			tp[i] = 0; dfs1(i);
		} else mx = i;
	}
	
	rep(i, n) if(S[i] == ')' && tp[i] == 0 && tp[to[i]] == 2) tp[i] = 2;
	rep(i, n) if(tp[i] == 2) putchar(S[i]); putchar('\n');
	return 0;
}