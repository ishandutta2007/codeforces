#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, a[200005], mxr[200005];
vector<int> occ[200005], val, rp[200005];
multiset<int> S;
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	val.clear();
	rep(i, n) val.push_back(a[i]);
	sort(val.begin(), val.end());
	val.resize(unique(val.begin(), val.end()) - val.begin());
	rep(i, n) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
	
	rep(i, n) occ[i].clear();
	rep(i, n) occ[a[i]].push_back(i);
	
	rep(i, n) mxr[i] = i;
	rep(i, m) {
		int l, r;
		scanf("%d%d", &l, &r); l --; r --;
		mxr[l] = max(mxr[l], r);
	}
	rep(i, n - 1) mxr[i + 1] = max(mxr[i + 1], mxr[i]);
	
	int L = n, R = -1;
	S.clear();
	rep(i, n) rp[i].clear();
	rep(i, n) {
		int p0 = lower_bound(occ[a[i]].begin(), occ[a[i]].end(), i) - occ[a[i]].begin(),
		p1 = upper_bound(occ[a[i]].begin(), occ[a[i]].end(), mxr[i]) - occ[a[i]].begin() - 1;
		if(p0 == p1) continue;
		L = min(L, occ[a[i]][p0 + 1]);
		R = max(R, occ[a[i]][p0]);
		S.insert(occ[a[i]][p0]);
		rp[occ[a[i]][p0]].push_back(occ[a[i]][p1]);
	}
	S.insert(R);
	
	int ans = n;
	rep(i, n) {
		if(i <= L) ans = min(ans, max(0, *S.rbegin() - i + 1));
		rep(j, rp[i].size()) {
			S.erase(S.find(i)); S.insert(rp[i][j]);
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}