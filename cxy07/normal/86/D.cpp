//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 10;

struct Q {
	int l,r,id;
	inline void read(int _id) {
		scanf("%lld%lld",&l,&r);
		id = _id;
	}
} q[MAXN];

int n,t;
int siz,blk,l = 1,r = 0;
int bl[MAXN],a[MAXN];
int ans[MAXN],now,cnt[MAXN];

inline bool cmp(Q a,Q b) {
	return (bl[a.l] ^ bl[b.l]) ? (bl[a.l] < bl[b.l]) : ((bl[a.l] & 1) ? a.r < b.r : a.r > b.r);
}

inline void Add(int x) {
	x = a[x];
	now -= cnt[x] * cnt[x] * x;
	cnt[x]++;
	now += cnt[x] * cnt[x] * x;
}

inline void Del(int x) {
	x = a[x];
	now -= cnt[x] * cnt[x] * x;
	cnt[x]--;
	now += cnt[x] * cnt[x] * x;
}

signed main () {
	scanf("%lld%lld",&n,&t);
	siz = sqrt(n);
	blk = ceil((double)n / siz);
	for(register int i = 1;i <= blk; ++i)
		for(register int j = (i - 1) * siz + 1;j <= i * siz; ++j)
			bl[j] = i;
	for(register int i = 1;i <= n; ++i) 
		scanf("%lld",&a[i]);
	for(register int i = 1;i <= t; ++i) 
		q[i].read(i);
	sort(q + 1,q + t + 1,cmp);
	for(register int i = 1,L,R;i <= t; ++i) {
		L = q[i].l,R = q[i].r;
		while(l < L) Del(l++);
		while(l > L) Add(--l);
		while(r < R) Add(++r);
		while(r > R) Del(r--);
		ans[q[i].id] = now;
	}
	for(register int i = 1;i <= t; ++i)
		printf("%lld\n",ans[i]);
	return 0;
}