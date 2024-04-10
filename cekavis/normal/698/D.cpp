#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005, K = 10;
int k, n, tot, q[K], p[K], cnt[K][N], f[K][N][K];
bool ans[N], vis[N];
struct item{
	int x, y;
	bool operator<(const item &r)const{ return x==r.x?y>r.y:x<r.x;}
	item operator-(const item &r)const{ return (item){x-r.x, y-r.y};}
	ll operator*(const item &r)const{ return (ll)x*r.x+(ll)y*r.y;}
	ll operator^(const item &r)const{ return (ll)x*r.y-(ll)y*r.x;}
} a[K], b[N];
int main() {
	scanf("%d%d", &k, &n);
	for(int i=1; i<=k; ++i) scanf("%d%d", &a[i].x, &a[i].y), p[i]=i;
	for(int i=1; i<=n; ++i) scanf("%d%d", &b[i].x, &b[i].y);
	for(int i=1; i<=k; ++i) for(int j=1; j<=n; ++j)
		for(int t=1; t<=n && cnt[i][j]<=k; ++t)
			if(!((b[t]-a[i])^(b[j]-a[i])) && ((a[i]-b[t])*(b[j]-b[t]))<0)
				f[i][j][++cnt[i][j]]=t;
	do{
		for(int i=1; i<=n; ++i){
			int t=1;
			vis[q[1]=i]=1;
			for(int j=1; j<=t && t<=k; ++j)
				for(int x=1, y; x<=cnt[p[j]][q[j]]; ++x)
					if(!vis[y=f[p[j]][q[j]][x]]) vis[q[++t]=y]=1;
			for(int j=1; j<=t; ++j) vis[q[j]]=0;
			if(t<=k) tot+=!ans[i], ans[i]=1;
		}
	} while(next_permutation(p+1, p+k+1));
	printf("%d\n", tot);
	return 0;
}