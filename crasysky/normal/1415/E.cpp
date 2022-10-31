#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long 
using namespace std;
const int N=1e6+6; 
int a[N]; priority_queue<ll> q;
int main(){
	int n,k; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n),reverse(a+1,a+1+n);
	rep(i,1,k+1) q.push(0);
	ll s=0;
	rep(i,1,n){
		ll x=q.top(); q.pop(); s+=x,q.push(x+a[i]);
	}
	printf("%lld\n",s);
	return 0;
}