#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

#define Query pair<pair<ll, ll>, pair<ll, ll>>
#define left first.first
#define right first.second
#define height second.first
#define num second.second

const ll MAXN = 3e5 + 100;
const ll SQRT = 320;
const ll MOD = 1e9 + 7;
const ll B1 = 701;
const ll B2 = 721;

ll n, q, par[MAXN];
ll ss[MAXN];
ll s_t[MAXN], f_t[MAXN], sz, depth[MAXN], ans[MAXN], rev[MAXN];
vector<ll>	adj[MAXN];
Query sec[MAXN];
ll cnt[2 * MAXN], gec[MAXN], cn[MAXN];
map<ll, ll>	ord;

bool cmp(Query a, Query b){
	if (a.left/SQRT != b.left/SQRT)
		return	a.left < b.left;
	return	a.right < b.right;
}

ll hs(string t){
	ll h1 = 0;
	for (char ch:t)
		h1 = ((ll)h1 * B2 + ch) % MOD;
	return	h1;
}

ll merge(ll a, ll b){return	(a << 30) ^ b;}

void build(ll v, ll de = 0){
	rev[sz] = v;
	s_t[v] = sz++;
	depth[v] = de;
	for (ll u:adj[v])
		build(u, de + 1);
	f_t[v] = sz;
}

void add(ll v){
	cnt[ss[v]]++;
	if (cnt[ss[v]] == 1)	
		cn[depth[v]]++;
}

void mi(ll v){
	cnt[ss[v]]--;
	if (cnt[ss[v]] == 0)
		cn[depth[v]]--;
}

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++){
		char temp[30];	scanf("%s", temp);
		ss[i] = hs(temp);
		scanf("%I64d", &par[i]);	par[i]--;
		if (par[i] != -1)
			adj[par[i]].push_back(i);
	}
	for (ll i = 0; i < n; i++)
		if (par[i] == -1)
			build(i);
	{
		for (ll i = 0; i < n; i++){
			ss[i] = merge(ss[i], depth[i]);
			gec[i] = ss[i];
		}
		sort(gec, gec + n);
		ll m = unique(gec, gec + n) - gec;
		for (ll i = 0; i < m; i++)
			ord[gec[i]] = i;
		
		for (ll i = 0; i < n; i++)
			ss[i] = ord[ss[i]];
	}
	
	scanf("%I64d", &q);
	for (ll i = 0; i < q; i++){
		ll v, k;	scanf("%I64d%I64d", &v, &k);	v--;
		sec[i].left = s_t[v];
		sec[i].right = f_t[v];
		sec[i].height = k;
		sec[i].num = i;
	}
	sort(sec, sec + q, cmp);

	ll l = 0, r = 0;
	for (ll i = 0; i < q; i++){
		ll tl = sec[i].left, tr = sec[i].right;
		while (r < tr){
			ll v = rev[r++];
			add(v);
		}
		while (l > tl){
			ll v = rev[--l];
			add(v);
		}
		while (r > tr){
			ll v = rev[--r];
			mi(v);
		}
		while (l < tl){
			ll v = rev[l++];
			mi(v);
		}
		ans[sec[i].num] = cn[depth[rev[sec[i].left]] + sec[i].height];
	}
	for (ll i = 0; i < q; i++)
		printf("%I64d\n", (ll)ans[i]);
	return 0;
}