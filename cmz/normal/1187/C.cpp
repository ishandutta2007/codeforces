#include<bits/stdc++.h>
const int MAXN = 1000+5;
int a[MAXN],n,m;
struct Q {
	int t,l,r;
	bool operator < (const Q &o) const {
		if(t != o.t) return t > o.t;
		return l == o.l ? r < o.r : l < o.l;
	}
} q[MAXN],t0[MAXN],t1[MAXN];
const int BIG = 2;
int cnt0,cnt1;
int kkkkkkkk;
std::vector<int> ss;
inline bool judge(int l,int r) {
	ss.clear();
	for (int i=l; i<=r; ++i) ss.push_back(a[i]);
	sort(ss.begin(),ss.end());
	int pos = l;
	for(auto x:ss) {
		if(x != a[pos]) return false;
		pos++;
	}
	return true;
}
int cf[MAXN];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; ++i) {
		int l,r,t;
		scanf("%d%d%d",&t,&l,&r);
		q[i] = (Q) {
			t,l,r
		};
		if(t == 1) t1[++cnt1] = q[i],t1[cnt1].l++;
		else t0[++cnt0] = q[i];
	}
	int sssss = 1000000;
	std::sort(t1+1,t1+cnt1+1);
	a[0] = n+5;
	int p = 1,st =0 ;
	for (int i=1; i<=n; ++i) {
		while(p <= cnt1 && t1[p].l <= i) st = std::max(st,t1[p++].r);
		if(st >= i) a[i] = a[i-1];
		else a[i] = a[i-1]-1;
	}
	for (int i=1; i<=n; ++i) if(!a[i]) a[i] = a[i-1];
	for (int i=1; i<=m; ++i) {
		int t = q[i].t,l = q[i].l,r = q[i].r;
		if(t == 0) {
			if(judge(l,r)) {
				puts("NO");
				return 0;
			}
		} else {
			if(!judge(l,r)) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for (int i=1; i<=n; ++i) printf("%d ",a[i]);
	puts("");
	return 0;
}