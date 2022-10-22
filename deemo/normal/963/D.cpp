#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define rank lkajsdf

const int MAXN = 4e5 + 10;
const int LOG = 20;

int n, q, c[MAXN], tn;
string s, t[MAXN];
int rank[LOG][MAXN], sa[MAXN], lp[LOG][MAXN];
pair<pii, int> sec[MAXN];

int lcp(int a, int b){
	int _a = a;
	for (int w = LOG-1; ~w && max(a, b) < n; w--)
		if (max(a, b) + (1<<w) <= n && rank[w][a] == rank[w][b])
			a += 1<<w, b += 1<<w;
	return a - _a;
}

int cnt[MAXN];
pair<pii, int> _gec[MAXN];
void srt(){
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[sec[i].F.S+1]++;
	for (int i = 1; i < MAXN; i++) cnt[i] += cnt[i-1];
	for (int i = 0; i < n; i++) _gec[--cnt[sec[i].F.S+1]] = sec[i];

	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[_gec[i].F.F+1]++;
	for (int i = 1; i < MAXN; i++) cnt[i] += cnt[i-1];
	for (int i = n-1; ~i; i--) sec[--cnt[_gec[i].F.F+1]] = _gec[i];
}

int sv[MAXN];
int getLcp(int a, int b){
	if (a == b) return n-a;
	a = rank[LOG-1][a], b = rank[LOG-1][b];
	if (a > b) swap(a, b);
	int t = b-a;
	return min(lp[sv[t]][a], lp[sv[t]][b - (1<<sv[t])]);
}

int ordQ[MAXN];
bool cmp2(int q1, int q2){
	if (t[q1].size() != t[q2].size())
		return t[q1].size() < t[q2].size();
	return t[q1] < t[q2];
}

int st[MAXN], ans[MAXN], qq[MAXN];
pii _sec[MAXN];

pii __gec[MAXN];
void _srt(int n){
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[_sec[i].S+1]++;
	for (int i = 1; i < MAXN; i++) cnt[i] += cnt[i-1];
	for (int i = 0; i < n; i++) __gec[--cnt[_sec[i].S+1]] = _sec[i];

	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[__gec[i].F+1]++;
	for (int i = 1; i < MAXN; i++) cnt[i] += cnt[i-1];
	for (int i = n-1; ~i; i--) _sec[--cnt[__gec[i].F+1]] = __gec[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	cin >> q;
	tn = s.size();
	for (int i = 0; i < q; i++) cin >> c[i] >> t[i], st[i] = s.size() + 1, s += "&"+t[i];
	n = s.size();

	for (int i = 0; i < n; i++) rank[0][i] = s[i];
	for (int w = 1; w < LOG; w++){
		for (int i = 0; i < n; i++)
			if (i + (1<<w-1) >= n)
				sec[i] = {{rank[w-1][i], -1}, i};
			else
				sec[i] = {{rank[w-1][i], rank[w-1][i+(1<<w-1)]}, i};
		srt();

		rank[w][sec[0].S] = 0;
		for (int i = 1; i < n; i++)
			if (sec[i].F == sec[i-1].F)
				rank[w][sec[i].S] = rank[w][sec[i-1].S];
			else
				rank[w][sec[i].S] = i;
	}
	for (int i = 0; i < n; i++)
		sa[rank[LOG-1][i]] = i;
	for (int i = 0; i + 1 < n; i++)
		lp[0][i] = lcp(sa[i], sa[i+1]);
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			if (i + (1<<w-1) >= n)
				lp[w][i] = 0;
			else
				lp[w][i] = min(lp[w-1][i], lp[w-1][i+(1<<w-1)]);

	for (int t = 1; t <= n; t++){
		sv[t] = 0;
		while (1<<sv[t]+1 <= t) sv[t]++;
	}

	iota(ordQ, ordQ + q, 0);
	sort(ordQ, ordQ + q, cmp2);

	memset(ans, 63, sizeof(ans));
	for (int l = 0; l < q;){
		int r = l;
		while (r < q && t[ordQ[l]].size() == t[ordQ[r]].size()) r++;

		int cur = 0, zz = 0;
		int _l = l;
		for (; l < r; l++){
			int id = ordQ[l];
			while (cur < n && (l + 1 == r || getLcp(st[id], sa[cur]) >= getLcp(st[ordQ[l+1]], sa[cur]))){
				if (sa[cur] < tn && getLcp(st[id], sa[cur]) >= t[id].size()){
					_sec[zz++] = {l, sa[cur]};
					//qq[tt++] = sa[cur];
					//if (tt >= c[id])
					//	ans[id] = min(ans[id], qq[tt-1] - qq[tt-c[id]] + (int)t[id].size());
				}
				cur++;
			}
		}
		l = _l;
		_srt(zz);
		int i = 0;
		for (; l < r; l++){
			int id = ordQ[l];
			int tt = 0;
			while (i < zz && _sec[i].F == l){
				qq[tt++] = _sec[i].S;
				if (tt >= c[id])
					ans[id] = min(ans[id], qq[tt-1] - qq[tt-c[id]] + (int)t[id].size());

				i++;
			}
		}
	}

	for (int i = 0; i < q; i++) {
		if (ans[i] > 1e9)
			ans[i] = -1;
		cout << ans[i] << "\n";
	}
	return 0;
}