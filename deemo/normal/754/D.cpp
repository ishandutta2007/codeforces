#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 3e5 + 10;
const int INF = 1e9 + 7;

int n, k, sec[MAXN], ans[MAXN], sz, gec[MAXN];
pair<ll, ll>	seg[MAXN];
bool fl = 0, del[MAXN];

bool cmp(int u, int v){return seg[u].S < seg[v].S;}
bool cmp2(int u, int v){return seg[u] < seg[v];}

bool ok(ll mid){
	memset(del, 0, sizeof(del));

	sz = 0;
	int cc = 0;
	int ptr = 0;
	for (int i = 0; i + k <= n; i++){
		int v = sec[i];
		while (ptr < n && seg[gec[ptr]].F <= seg[v].S-mid+1){
			if (!del[gec[ptr]])
				cc++;
			ptr++;
		}
		if (cc >= k){
			if (fl){
				for (int j = i; sz < k && j < n; j++){
					int u = sec[j];
					if (seg[u].F <= seg[v].S-mid+1)
						ans[sz++] = u;
				}
			}
			return true;
		}
		
		if (seg[v].F <= seg[v].S-mid+1)
			cc--;
		del[v] = 1;
	}
	if (fl){
		for (int i = 0; i < k; i++)
			ans[sz++] = i;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> seg[i].F >> seg[i].S;
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	iota(gec, gec+n, 0);
	sort(gec, gec+n, cmp2);

	ll lo = 0, hi = 3e9;
	while (hi-lo>1){
		ll mid = hi+lo>>1;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	fl = 1;
	ok(lo);
	cout << lo << "\n";
	sort(ans, ans+k);
	for (int i = 0; i < k; i++)
		cout << ans[i]+1 << " ";
	cout << "\n";
	return 0;
}