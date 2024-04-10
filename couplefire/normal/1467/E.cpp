#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 2e18;
const long long mod = 1e9+7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 1000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,co,in[200005],out[200005],pos[200005];
int a[200005],dep[200005],sp[200005][20],p[200005];
int sum[200005];
vec v[200005],num;
vecpi m;

void dfs(int x,int pr,int depth) {
	in[x] = ++co;
	dep[x] = depth;
	pos[co] = x;
	p[x] = sp[x][0] = pr;
	for(int i : v[x]) if(i^pr) dfs(i,x,depth+1);
	out[x] = co;
}

bool cmp(int x,int y) {return dep[x] < dep[y];}

int LCA(int x,int y) {
	if(dep[x] > dep[y]) swap(x,y);
	for(int i = 19;i >= 0;i--) {
		if(dep[x]+(1 << i) <= dep[y]) y = sp[y][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;i--) {
		if(sp[x][i]^sp[y][i]) x = sp[x][i], y = sp[y][i];
	}
	return sp[x][0];
}

int t[200005];

void update(int x,int val) {
	for(;x <= n;x += x&-x) t[x] += val;
}

int query(int l,int r) {
	int ret = 0;
	for(;r;r -= r&-r) ret += t[r];
	for(l--;l;l -= l&-l) ret -= t[l];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i], m.pb({a[i],i});
	for(int i = 1;i < n;i++) {
		int x,y; cin >> x >> y;
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1,-1,1);
	for(int i = 1;i < 20;i++) {
		for(int j = 1;j <= n;j++) sp[j][i] = sp[sp[j][i-1]][i-1];
	}
	sort(all(m));
	int nope = 0;
	for(int i = 0;i < m.size();) {
		int l = i, r = i;
		num.clear();
		while(m[i].x == m[r].x) num.pb(m[r].y), r++; i = r;
		if(num.size() == 1) continue;
		int mx = 0,conr = 0,cnt = 0;
		sort(all(num),cmp);
		for(int i : num) {
			int lca = LCA(num[0],i);
			if(lca != num[0]) conr = 1;
		}
		for(int i : num) update(in[i],1);
		for(int i : num) {
			int cnt = 0;
			if((int)num.size()-query(in[i],out[i])) cnt++;
			for(int j : v[i]) {
				if(j == p[i]) continue;
				if(query(in[j],out[j])) cnt++;
			}
			if(cnt >= 2) {
				cout << 0;
				return 0;
			}
		}
		int wh = -1;
		for(int j : v[num[0]]) {
			if(j == p[num[0]]) continue;
			if(query(in[j],out[j])) wh = j;
		}
		for(int i : num) update(in[i],-1);
		if(conr) for(int i : num) sum[in[i]]++, sum[out[i]+1]--;
		else {
			if(wh == -1) return -1;
			sum[1]++, sum[n+1]--;
			sum[in[wh]]--, sum[out[wh]+1]++;
			for(int i = 1;i < num.size();i++) {
				sum[in[num[i]]]++, sum[out[num[i]]+1]--;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		sum[i] += sum[i-1];
		if(!sum[i]) ans++;
	}
	cout << ans;
}