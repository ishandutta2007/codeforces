#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 5e5 + 10;

int n, x, y, z, xx[MAXN], yy[MAXN], zz[MAXN], sec[MAXN];
ll fen[MAXN];

bool cmp(int u, int v){return xx[u] < xx[v];}

void add(int v, ll val){for (v++; v<MAXN; v+=v&-v) fen[v]+=val;}
ll get(int v){
	ll ret = 0;
	for (; v; v-=v&-v) ret += fen[v];
	return ret;
}

vector<pii> remy, remz;
int py[MAXN], pz[MAXN];
int gg[MAXN];
int main(){
	memset(gg, -1, sizeof(gg));
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d %d %d %d", &n, &x, &y, &z);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &xx[i], &yy[i], &zz[i]), xx[i]--, yy[i]--, zz[i]--;
		remy.push_back({xx[i], yy[i]+1});
		remz.push_back({xx[i], zz[i]+1});
	}
	sort(remy.begin(), remy.end());
	sort(remz.begin(), remz.end());
	py[n] = pz[n] = 0;
	for (int i = n-1; ~i; i--)
		py[i] = max(remy[i].S, py[i+1]), pz[i] = max(remz[i].S, pz[i+1]);

	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	ll ans = 0;
	int cur = 0, ptr = 0;
	int tz = z;
	for (int i = 0; i < x; i++){
		while (cur < n && xx[sec[cur]] < i){
			int v = sec[cur++];
			gg[zz[v]] = max(gg[zz[v]], yy[v]);
		}

		int minY = py[cur], minZ = pz[cur];

		while (tz > minZ){
			tz--;
			if (~gg[tz]){
				int t = gg[tz];
				while (ptr <= t)
					add(ptr++, tz+1);
			}
		}

		ll temp = get(y) - get(minY);
		temp += 1ll*(y-max(minY, ptr))*minZ;
		ans += 1ll*(y-minY)*z - temp;
	}
	printf("%lld\n", ans);
	return 0;
}