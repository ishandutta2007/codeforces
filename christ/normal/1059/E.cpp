#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5 + 2, LOG = 21, INF = 1e8;
int w[MN], l; ll s; vector<int> adj[MN];
struct Info {
	int len, ans; ll sum;
	bool operator< (const Info &o) const {
		return mp(sum,mp(len,ans)) > mp(o.sum,mp(o.len,o.ans));
	}
} lz[MN];
struct cmp {bool operator() (const Info &a, const Info &b) const {return mp(a.len,mp(a.sum,a.ans)) > mp(b.len,mp(b.sum,b.ans));}};
multiset<int> anss[MN];
multiset<Info> srtSum[MN];
multiset<Info,cmp> srtLen[MN];
void dfs (int cur) {
	int tot = 0, big = 0;
	for (int i : adj[cur]) {
		dfs(i);
		if ((int)anss[i].size() > (int)anss[big].size()) big = i;
		tot += *anss[i].begin() + lz[i].ans;
	}
	if (big) {
		lz[cur] = {lz[big].len + 1,tot - *anss[big].begin(),lz[big].sum + w[cur]};
		swap(anss[cur],anss[big]); swap(srtSum[cur],srtSum[big]); swap(srtLen[cur],srtLen[big]);
	}
	Info go = {1 - lz[cur].len, tot + 1 - lz[cur].ans, w[cur] - lz[cur].sum};
	anss[cur].insert(go.ans); srtSum[cur].insert(go); srtLen[cur].insert(go);
	assert((int)anss[cur].size() == (int)srtSum[cur].size());
	for (int i : adj[cur]) if (i != big) {
		for (Info p : srtSum[i]) {
			go = {p.len + 1 + lz[i].len - lz[cur].len,p.ans + tot - *anss[i].begin() - lz[cur].ans,p.sum + lz[i].sum + w[cur] - lz[cur].sum};
			anss[cur].insert(go.ans);
			srtSum[cur].insert(go);
			srtLen[cur].insert(go);
		}
	}
	while (!srtSum[cur].empty() && srtSum[cur].begin()->sum + lz[cur].sum > s) {
		go = *srtSum[cur].begin();
		anss[cur].erase(anss[cur].find(go.ans));
		srtLen[cur].erase(srtLen[cur].find(go));
		srtSum[cur].erase(srtSum[cur].find(go));
	}
	while (!srtLen[cur].empty() && srtLen[cur].begin()->len + lz[cur].len > l) {
		go = *srtLen[cur].begin();
		anss[cur].erase(anss[cur].find(go.ans));
		srtLen[cur].erase(srtLen[cur].find(go));
		srtSum[cur].erase(srtSum[cur].find(go));
	}
}
int main () { 
	int n;
	scanf ("%d %d %lld",&n,&l,&s);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&w[i]);
		if (w[i] > s) return !printf ("-1\n");
	}
	for (int i = 2; i <= n; i++) {
		int p; scanf ("%d",&p); adj[p].push_back(i);
	} 
	dfs(1);
	printf ("%d\n",*anss[1].begin() + lz[1].ans);
    return 0;
}