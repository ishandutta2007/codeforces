#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int K = 6, N = 150005;

int n, m, p, L, R, a[N], cov[N<<2];
struct st{
	int a[K], b[K];
	inline st operator +(const st &rhs)const{
		st ass=*this;
		for(int i=1; i<=p; ++i) if(rhs.a[i]){
			int j=1;
			for(; j<=p; ++j) if(ass.a[j]==rhs.a[i]) break;
			if(j<=p) ass.b[j]+=rhs.b[i];
			else{
				int mn=1e9;
				for(j=1; j<=p; ++j) mn=min(mn, ass.b[j]);
				if(mn>=rhs.b[i]) for(j=1; j<=p; ++j) ass.b[j]-=rhs.b[i];
				else{
					for(j=1; j<=p; ++j) ass.b[j]-=mn;
					for(j=1; j<=p; ++j) if(!ass.b[j]){
						ass.a[j]=rhs.a[i], ass.b[j]=rhs.b[i]-mn;
						break;
					}
				}
			}
		}
		return ass;
	}
}s[N<<2];
void build(int l, int r, int t){
	if(l==r) return (void)(s[t].a[1]=a[l], s[t].b[1]=1);
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=s[k]+s[k|1];
}
void change(int l, int r, int t, int val){
	if(L<=l && r<=R){
		cov[t]=val, memset(s+t, 0, K<<3);
		s[t].a[1]=val, s[t].b[1]=r-l+1;
		return;
	}
	int mid=(l+r)>>1, k=t<<1;
	if(cov[t])
		cov[k]=cov[k|1]=cov[t],
		memset(s+k, 0, K<<4), s[k].a[1]=cov[t], s[k].b[1]=mid-l+1,
		s[k|1].a[1]=cov[t], s[k|1].b[1]=r-mid,
		cov[t]=0;
	if(L<=mid) change(l, mid, k, val);
	if(R>mid) change(mid+1, r, k|1, val);
	s[t]=s[k]+s[k|1];
}
st query(int l, int r, int t){
	if(L<=l && r<=R) return s[t];
	int mid=(l+r)>>1, k=t<<1;
	if(cov[t])
		cov[k]=cov[k|1]=cov[t],
		memset(s+k, 0, K<<4), s[k].a[1]=cov[t], s[k].b[1]=mid-l+1,
		s[k|1].a[1]=cov[t], s[k|1].b[1]=r-mid,
		cov[t]=0;
	if(R<=mid) return query(l, mid, k);
	if(L>mid) return query(mid+1, r, k|1);
	return query(l, mid, k)+query(mid+1, r, k|1);
}
int main() {
	scanf("%d%d%d", &n, &m, &p), p=100/p;
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	build(1, n, 1);
	while(m--){
		int opt, x;
		scanf("%d%d%d", &opt, &L, &R);
		if(opt==1) scanf("%d", &x), change(1, n, 1, x);
		else{
			st tmp=query(1, n, 1);
			printf("%d", p);
			for(int i=1; i<=p; ++i) printf(" %d", tmp.a[i]);
			puts("");
		}
	}
	return 0;
}