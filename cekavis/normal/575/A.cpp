#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 50005, M = 62;
ll k;
int p, n, m, P, s[N];
pair<ll,int> a[N];
struct matrix{
	int a[2][2];
	matrix(){}
	matrix(int x, int y){ a[0][0]=x, a[1][0]=y, a[0][1]=1, a[1][1]=0;}
	int *operator[](int x){ return a[x];}
	const int *operator[](int x)const{ return a[x];}
	matrix operator*(const matrix &r)const{
		matrix ans;
		ans[0][0]=((ll)a[0][0]*r[0][0]+(ll)a[0][1]*r[1][0])%P;
		ans[0][1]=((ll)a[0][0]*r[0][1]+(ll)a[0][1]*r[1][1])%P;
		ans[1][0]=((ll)a[1][0]*r[0][0]+(ll)a[1][1]*r[1][0])%P;
		ans[1][1]=((ll)a[1][0]*r[0][1]+(ll)a[1][1]*r[1][1])%P;
		return ans;
	}
	void operator*=(const matrix &r){ *this=*this*r;}
	void print(){
		printf("[%d %d]\n[%d %d]\n\n", a[0][0], a[0][1], a[1][0], a[1][1]);
	}
} ans, g[M], f[N<<2];
void build(int l, int r, int t){
	if(l==r) return (void)(f[t]=matrix(s[l+1], s[l]));
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	f[t]=f[k]*f[k|1];
}
matrix query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return f[t];
	int mid=(l+r)>>1, k=t<<1;
	if(R<=mid) return query(l, mid, k, L, R);
	if(L>mid) return query(mid+1, r, k|1, L, R);
	return query(l, mid, k, L, R)*query(mid+1, r, k|1, L, R);
}
matrix calc(ll l, ll r){
	if(l/n==r/n) return query(0, n-1, 1, l%n, r%n);
	matrix ans=query(0, n-1, 1, l%n, n-1);
	ll x=r/n-l/n-1;
	for(int i=0; 1ll<<i<=x; ++i) if(x>>i&1) ans*=g[i];
	return ans*query(0, n-1, 1, 0, r%n);
}
int main() {
	scanf("%lld%d%d", &k, &P, &n);
	for(int i=0; i<n; ++i) scanf("%d", s+i);
	s[n]=s[0];
	build(0, n-1, 1), g[0]=f[1];
	for(int i=1; i<60; ++i) g[i]=g[i-1]*g[i-1];
	scanf("%d", &m);
	for(int i=0; i<m; ++i){
		scanf("%lld%d", &a[i].first, &a[i].second);
		if(a[i].first>=k) --i, --m;
	}
	sort(a, a+m);
	ans[0][0]=ans[1][1]=1;
	ll now=1, x;
	for(int i=0; i<m; ++i){
		if(now<(x=a[i].first)) ans*=calc(now-1, x-2), now=x;
		if(now==x) ans*=matrix(a[i].second, s[(x-1)%n]), ++now;
		ans*=matrix((a[i+1].first==x+1 && i<m-1?a[i+1].second:s[(x+1)%n]), a[i].second);
		++now;
	}
	if(now<=k) ans*=calc(now-1, k-1);
	printf("%d\n", ans[0][1]);
	return 0;
}