#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e6 + 10;

struct Q {
	int l,r,id;
} q[MAXN];

int n,m,k;
int blk,siz,bl[MAXN];
int a[MAXN],x[MAXN];
int cnt[MAXN << 2],ans[MAXN];
int now;

inline bool cmp(Q a,Q b) {return ((bl[a.l] ^ bl[b.l]) ? bl[a.l] < bl[b.l] : ((bl[a.l] & 1) ? a.r < b.r : a.r > b.r));}

inline void add(int pos) {
	now += cnt[k ^ x[pos]];
	cnt[x[pos]]++;
}

inline void del(int pos) {
	cnt[x[pos]]--;
	now -= cnt[k ^ x[pos]];
}

signed main () {
	scanf("%lld%lld%lld",&n,&m,&k);
	for(register int i = 1;i <= n; ++i)
		scanf("%lld",&a[i]),x[i] = x[i - 1] ^ a[i];
	siz = sqrt(n);
	blk = ceil((double) n / siz);
	for(register int i = 1;i <= blk; ++i)
		for(register int j = (i - 1) * siz + 1;j <= i * siz; ++j)
			bl[j] = i;
	for(register int i = 1;i <= m; ++i) {
		scanf("%lld%lld",&q[i].l,&q[i].r);
		q[i].l--;
		q[i].id = i;
	}
	sort(q + 1,q + m + 1,cmp);
	int l = 1,r = 0;
	for(register int i = 1,L,R;i <= m; ++i) {
		L = q[i].l,R = q[i].r;
		while(l < L) del(l++);
		while(l > L) add(--l);
		while(r < R) add(++r);
		while(r > R) del(r--);
		ans[q[i].id] = now;
	}
	for(register int i = 1;i <= m; ++i)
		printf("%lld\n",ans[i]);
	return 0;
}