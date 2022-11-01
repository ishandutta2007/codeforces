#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 150005;
int n;
ll sum;
pair<int,int> a[N];
struct item{
	int p;
	ll l, r;
	bool operator<(const item &r)const{ return p<r.p;}
} b[N];
bool cmp(const pair<int,int> &x, const pair<int,int> &y){
	return (ll)x.second*y.first<(ll)x.first*y.second;
}
bool check(double x){
	double mx=0;
	for(int i=1; i<=n; ++i){
		int j=i;
		while(j<n && b[j].p==b[j+1].p) ++j;
		for(int k=i; k<=j; ++k) if(b[k].p*(1-x*b[k].r/sum)<mx) return 0;
		for(int k=i; k<=j; ++k) mx=max(mx, b[k].p*(1-x*b[k].l/sum));
		i=j;
	}
	return 1;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i].first);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i].second);
	sort(a+1, a+n+1, cmp);
	for(int i=1; i<=n; ++i){
		ll now=sum;
		sum+=a[i].second;
		int j=i;
		while(j<n && !cmp(a[j], a[j+1])) ++j, sum+=a[j].second;
		for(int k=i; k<=j; ++k) b[k]=(item){a[k].first, now+a[k].second, sum};
		i=j;
	}
	sort(b+1, b+n+1);
	double l=0, r=1;
	for(int i=0; i<25; ++i){
		double mid=(l+r)/2;
		if(check(mid)) l=mid; else r=mid;
	}
	printf("%.9lf\n", l);
	return 0;
}