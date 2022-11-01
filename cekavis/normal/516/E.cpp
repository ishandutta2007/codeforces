#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, m, g, x, im, vis[N*2];
ll ans, d[N*2];
vector<int> a[N*2], b[N*2];
int Pow(ll x, int y, int P){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int phi(int x){
	int ans=x;
	for(int i=2; i*i<=x; ++i) if(x%i==0){
		do x/=i; while(x%i==0);
		ans=ans/i*(i-1);
	}
	if(x>1) ans=ans/x*(x-1);
	return ans;
}
ll solve(vector<int> &x, vector<int> &y){
	int xx=x.size(), yy=y.size();
	if(xx+yy>=n){
		memset(vis, 0, n<<2);
		int cnt=0;
		for(int i:x) cnt+=!vis[i]++;
		for(int i:y) cnt+=!vis[i]++;
		if(cnt==n){
			for(int i=m; i--;) if(vis[i]<2) return i;
			return -2;
		}
	}
	if(!xx && !yy) puts("-1"), exit(0);
	x.insert(x.end(), y.begin(), y.end());
	for(int &i:x) i=(ll)i*im%n;
	sort(x.begin(), x.end()), x.resize(unique(x.begin(), x.end())-x.begin());
	int s=x.size();
	for(int i=0; i<s; ++i) d[i]=(ll)x[i]*m%n;
	for(int i=1; i<s; ++i) d[i]=min(d[i], d[i-1]+(ll)(x[i]-x[i-1])*m);
	d[0]=min(d[0], d[s-1]+(ll)(x[0]-x[s-1]+n)*m);
	for(int i=1; i<s; ++i) d[i]=min(d[i], d[i-1]+(ll)(x[i]-x[i-1])*m);
	ll ans=x[s-1]-x[0]==n-1?0:d[s-1]+(ll)(x[0]-x[s-1]+n-1)*m;
	for(int i=1; i<s; ++i) if(x[i-1]<x[i]-1)
		ans=max(ans, d[i-1]+(ll)(x[i]-x[i-1]-1)*m);
	return ans;
}
int main() {
	scanf("%d%d", &n, &m), g=__gcd(n, m), n/=g, m/=g;
	if(g>200000) return puts("-1"), 0;
	scanf("%d", &x);
	for(int i=1, y; i<=x; ++i) scanf("%d", &y), a[y%g].push_back(y/g);
	scanf("%d", &x);
	for(int i=1, y; i<=x; ++i) scanf("%d", &y), b[y%g].push_back(y/g);
	if(n<m){
		swap(n, m);
		for(int i=0; i<g; ++i) swap(a[i], b[i]);
	}
	im=Pow(m, phi(n)-1, n);
	for(int i=0; i<g; ++i) ans=max(ans, solve(a[i], b[i])*g+i);
	printf("%lld\n", ans);
	return 0;
}