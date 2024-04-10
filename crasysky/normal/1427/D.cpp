#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int a[102],p[102],c[102]; vector<int> v[102];
int main(){
	int n,m=0; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	while (true){
		rep(i,1,n) p[a[i]]=i;
		int b=0;
		rep(i,1,n-1)
			if (p[i+1]<p[i]){ b=i; break; }
		if (!b) break;
		int t=p[b+1]; while (a[t+1]==a[t]+1) ++t;
		++m;
		if (p[b+1]>1) v[m].push_back(p[b+1]-1);
		v[m].push_back(t-p[b+1]+1),v[m].push_back(p[b]-t);
		if (p[b]<n) v[m].push_back(n-p[b]);
		int k=0;
		rep(i,p[b]+1,n) c[++k]=a[i];
		rep(i,t+1,p[b]) c[++k]=a[i];
		rep(i,p[b+1],t) c[++k]=a[i];
		rep(i,1,p[b+1]-1) c[++k]=a[i];
		rep(i,1,n) a[i]=c[i];
	}
	printf("%d\n",m);
	rep(i,1,m){
		printf("%d ",v[i].size());
		rep0(j,v[i].size()) printf("%d ",v[i][j]);
		putchar('\n');
	}
	return 0;
}