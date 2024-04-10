#include <bits/stdc++.h>
using namespace std;
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5 + 5, INF = 1e9;
struct Seg {
	long long tree[MN<<2];
	Seg () {memset(tree,0x3f,sizeof tree);}
	void update (int ind, int tl, int tr, int l, int r, long long v) {
		if (tl > r || tr < l) return;
		if (l <= tl && tr <= r) {
			tree[ind] = min(tree[ind],v);
			return;
		}
		int mid = (tl + tr) / 2;
		update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
	}
	long long query (int ind, int tl, int tr, int i) {
		long long ret = tree[ind];
		if (tl == tr) return ret;
		int mid = (tl + tr) / 2;
		if (i <= mid) ret = min(ret,query(lc,tl,mid,i));
		else ret = min(ret,query(rc,mid+1,tr,i));
		return ret;
	}
} segC, segA;
int main() {
	int n; scanf ("%d",&n); long long sum = 0;
	vector<array<int,2>> got(n);
	for (auto &[a,c] : got) scanf ("%d %d",&a,&c), sum += c;
	sort(got.begin(),got.end());
	segC.update(1,1,n,1,1,0);
	vector<long long> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = min(segC.query(1,1,n,i+1),segA.query(1,1,n,i+1)+got[i][0]);
		int pos = lower_bound(got.begin(),got.end(),array{got[i][0]+got[i][1],0}) - got.begin();
		segC.update(1,1,n,i+1,pos,dp[i]);
		segA.update(1,1,n,pos+1,n,dp[i]-got[i][0]-got[i][1]);
	}
	printf ("%lld\n",dp[n-1]+sum);
    return 0;
}