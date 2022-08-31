#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
char mat[1505][1505];
vector<int> ans;
struct pqt
{
	int sta[5005], ssiz;
	void rec_id(int x)
	{
		sta[ssiz ++] = x;
	}
	int get_id()
	{
		return sta[-- ssiz];
	}
	
	int tp[5005], cnt;
	vector<int> T[5005];
	
	void init()
	{
		cnt = n + 1;
		rep(i, n) tp[i] = -1;
		tp[n] = 0;
		rep(i, n) T[n].push_back(i);
		rep(i, 2 * n + 100) rec_id(cnt + i);
	}
	
	bool hv[5005];
	int hvt[5005], siz[5005];
	void dfs0(int v)
	{
		if(tp[v] == -1) {
			hvt[v] = hv[v] ? 2 : 1; siz[v] = hv[v];
		} else {
			hvt[v] = siz[v] = 0;
			rep(i, T[v].size()) {
				int u = T[v][i];
				dfs0(u); hvt[v] |= hvt[u]; siz[v] += siz[u];
			}
		}
	}
	int findl(int v)
	{
		rep(i, T[v].size()) {
			int u = T[v][i];
			if(siz[u] == siz[v]) return findl(u);
		}
		return v;
	}
	
	vector<int> X, Y, Z, V, U[2];
	bool calc(int v, vector<int>& ret)
	{
		if(tp[v] == 1) {
			if(hvt[T[v][0]] == 2 || (hvt[T[v][0]] == 3 && hvt[T[v].back()] == 1)) reverse(T[v].begin(), T[v].end());
			int ctp = 1;
			rep(i, T[v].size()) {
				int u = T[v][i];
				if(ctp == 2 && hvt[u] != 2) return false;
				if(hvt[u] == 3) {
					if(!calc(u, ret)) return false;
				} else ret.push_back(u);
				if(hvt[u] != 1) ctp = 2;
			}
		} else {
			V.clear();
			rep(i, T[v].size()) if(hvt[T[v][i]] == 1) V.push_back(T[v][i]);
			if(V.size() == 1) ret.push_back(V[0]);
			else if(V.size() > 1) {
				int nr = get_id(); tp[nr] = 0; T[nr] = V;
				ret.push_back(nr);
			}
			V.clear();
			rep(i, T[v].size()) if(hvt[T[v][i]] == 3) V.push_back(T[v][i]);
			if(V.size() == 1) {
				if(!calc(V[0], ret)) return false;
			} else if(V.size() > 1) return false;
			V.clear();
			rep(i, T[v].size()) if(hvt[T[v][i]] == 2) V.push_back(T[v][i]);
			if(V.size() == 1) ret.push_back(V[0]);
			else if(V.size() > 1) {
				int nr = get_id(); tp[nr] = 0; T[nr] = V;
				ret.push_back(nr);
			}
		}
		rec_id(v);
		return true;
	}
	
	bool addrg()
	{
		dfs0(n);
		int rt = findl(n);
		if(hvt[rt] != 3) return true;
		
		X.clear(); Y.clear(); Z.clear(); U[0].clear(); U[1].clear();
		rep(i, T[rt].size()) if(hvt[T[rt][i]] == 3) X.push_back(T[rt][i]);
		else if(hvt[T[rt][i]] == 2) Y.push_back(T[rt][i]);
		else Z.push_back(T[rt][i]);
		if(X.size() > 2) return false;
		rep(i, X.size()) if(!calc(X[i], U[i])) return false;
		
		V.clear();
		if(tp[rt] == 1) {
			int mn = T[rt].size(), mx = -1;
			rep(i, T[rt].size()) if(hvt[T[rt][i]] != 1) {
				mn = min(mn, i); mx = max(mx, i);
			}
			if(mx - mn + 1 != (int)(X.size() + Y.size())) return false;
			rep(i, X.size()) if(X[i] != T[rt][mn] && X[i] != T[rt][mx]) return false;
			
			rep(i, X.size()) if(X[i] == T[rt][mx]) reverse(U[i].begin(), U[i].end());
			int px = 0;
			rep(i, T[rt].size()) if(hvt[T[rt][i]] == 3) {
				rep(j, U[px].size()) V.push_back(U[px][j]); px ++;
			} else V.push_back(T[rt][i]);
			T[rt] = V;
		} else {
			int ct;
			if(X.size() == 2) reverse(U[1].begin(), U[1].end());
			if(X.size() >= 1) {
				rep(i, U[0].size()) V.push_back(U[0][i]);
				if(Y.size() == 1) V.push_back(Y[0]);
				else if(Y.size() >= 2) {
					int nr = get_id(); tp[nr] = 0; T[nr] = Y;
					V.push_back(nr);
				}
				if(X.size() == 2) rep(i, U[1].size()) V.push_back(U[1][i]);
				ct = 1;
			} else {
				V = Y; ct = 0;
			}
			if(Z.empty()) {
				tp[rt] = ct; T[rt] = V;
			} else {
				int nr = get_id(); tp[nr] = ct; T[nr] = V;
				T[rt] = Z; T[rt].push_back(nr);
			}
		}
		
		return true;
	}
	
	void output(int v)
	{
		if(tp[v] == -1) ans.push_back(v);
		else rep(i, T[v].size()) output(T[v][i]);
	}
}tre;

char buf[1505][1505], otp[1505][1505];
int main()
{
	scanf("%d", &n); m = n;
	tre.init();
	
	rep(i, m) {
		scanf("%s", buf[i]);
		rep(j, n) tre.hv[j] = buf[i][j] == '1';
		if(!tre.addrg()) {
			printf("NO\n"); return 0;
		}
	}
	tre.output(n);
	
	rep(i, m) rep(j, n) otp[i][j] = buf[i][ans[j]];
	printf("YES\n");
	rep(i, m) printf("%s\n", otp[i]);
	return 0;
}