#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,INF=1e9;
priority_queue<int> pq1,pq2; pr a[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n){
		int x,y; scanf("%d%d",&x,&y);
		a[i]=mp(x+y,x);
	}
	sort(a+1,a+1+n);
	ll l=0,r=INF,s=0;
	rep(i,1,n){
		r+=a[i].fi-a[i-1].fi; int t=a[i].fi,x=a[i].se;
		if (l<=x&&x<=r) pq1.push(l),pq2.push(-(r-t)),l=r=x;
		else if (x<l)
			pq1.push(x),pq1.push(x),pq2.push(-(r-t)),s+=l-x,r=l,l=pq1.top(),pq1.pop();
		else 
			pq2.push(-(x-t)),pq2.push(-(x-t)),pq1.push(l),s+=x-r,l=r,r=-pq2.top()+t,pq2.pop();
	}
	printf("%lld\n",s);
	return 0;
}