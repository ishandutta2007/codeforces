#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, a, b, s[5005];
string sta[5005], sta2[5005];
char adj[5005][5005];
int cnt;
vector<int> hv[5005];
int hdr = -1, nxt[25];
string cur[25];
PII dat[5005];

vector<int> ps;
bool vis[5005];
void dfs0(int v)
{
	vis[v] = true;
	rep(i, n) if(adj[v][i] == '1' && !vis[i]) dfs0(i);
	ps.push_back(v);
}
void dfs1(int v, vector<int>& chv)
{
	vis[v] = true;
	chv.push_back(v);
	rep(i, n) if(adj[i][v] == '1' && !vis[i]) dfs1(i, chv);
}

void gen_scc()
{
	rep(i, n) vis[i] = false;
	rep(i, n) if(!vis[i]) dfs0(i);
	reverse(ps.begin(), ps.end());
	rep(i, n) vis[i] = false;
	rep(i, n) if(!vis[ps[i]]) dfs1(ps[i], hv[cnt ++]);
}

int comb[5005][5005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b;
	rep(i, n) cin >> adj[i];
	rep(i, n) {
		cin >> s[i] >> sta[i];
		sta2[i].resize(s[i], '0');
	}
	gen_scc();
	
	memset(nxt, -1, sizeof(nxt));
	rep(i, cnt) {
		rep(j, 25) if(cur[j].empty()) {
			nxt[j] = hdr;
			hdr = j;
			break;
		}
		int cg = 0;
		rep(j, hv[i].size()) cg = __gcd(cg, s[hv[i][j]]);
		cur[hdr].resize(cg, '0');
		rep(j, hv[i].size()) {
			int gan = hv[i][j];
			rep(k, s[gan]) cur[hdr][k % cg] |= sta[gan][k];
		}
		for(int j = hdr; j != -1; j = nxt[j]) {
			int nsiz = __gcd(cg, (int)cur[j].length());
			if(nsiz == cur[j].length()) continue;
			for(int k = nsiz; k < cur[j].length(); k ++) cur[j][k % nsiz] |= cur[j][k];
			cur[j].resize(nsiz);
		}
		for(int j = hdr; j != -1; j = nxt[j])
		while(nxt[j] != -1 && cur[nxt[j]].length() == cur[j].length()) {
			int nj = nxt[j];
			rep(k, cur[j].length()) cur[j][k] |= cur[nj][k];
			cur[nj].clear();
			nxt[j] = nxt[nj];
			nxt[nj] = -1;
		}
		rep(j, hv[i].size()) {
			int gan = hv[i][j];
			rep(k, s[gan]) for(int l = hdr; l != -1; l = nxt[l]) sta2[gan][k] |= cur[l][k % cur[l].length()];
		}
	}
	
	rep(i, n) rep(j, s[i]) {
		if(sta[i][j] == '1') dat[i].second ++;
		if(sta2[i][j] == '1') dat[i].first ++;
	}
	
	comb[0][0] = 1;
	rep1(i, n) {
		comb[i][0] = 1;
		rep1(j, n) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}
	
	sort(dat, dat + n);
	int ans = 0;
	for(int i = n - 1; i >= 0; i --) {
		int cnt0 = a - b, cnt1 = 0;
		rep(j, i) if(dat[j].second > dat[i].first) cnt0 --;
		for(int j = i + 1; j < n; j ++) if(dat[j].second > dat[i].first) cnt1 ++;
		for(int j = max(cnt1 - cnt0, 0); j <= min(cnt1, b - 1); j ++)
		ans = (ans + 1LL * comb[cnt1][j] * comb[n - i - 1 - cnt1][b - 1 - j]) % MOD;
	}
	cout << ans << endl;
	return 0;
}