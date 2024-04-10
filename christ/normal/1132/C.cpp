#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
int freq[MN], psa[MN];
int main () { 
	int n,q;
	scanf ("%d %d",&n,&q);
	vector<pii> go(q);
	for (auto &au : go) {
		scanf ("%d %d",&au.first,&au.second);
		for (int i = au.first; i <= au.second;i++) ++freq[i];
	}
	int mx = 0;
	for (int j = 0; j < q; j++) {
		for (int i = go[j].first; i <= go[j].second; i++) --freq[i];
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += !!freq[i];
		for (int i = 1; i <= n; i++) psa[i] = psa[i-1] + (freq[i]==1);
		int mn = INT_MAX;
		for (int k = 0; k < q; k++) if (k != j) {
			mn = min(mn,psa[go[k].second] - psa[go[k].first-1]);
		}
		mx = max(mx,cnt-mn);
		for (int i = go[j].first; i <= go[j].second; i++) ++freq[i];
	}
	printf ("%d\n",mx);
	return 0;
}