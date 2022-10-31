#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6;
int a[N],b[N];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
void exgcd(int a,int b,int &x,int &y){
	if (b==0){ x=1,y=0; return; }
	int tx,ty; exgcd(b,a%b,tx,ty);
	x=ty,y=tx-a/b*ty;
}
int l0[N],x[N],q[N];
int main(){
	int n,m; ll k; cin>>n>>m>>k;
	rep(i,1,n){ int x; scanf("%d",&x); a[x]=i; }
	rep(i,1,m){ int y; scanf("%d",&y); b[y]=i; }
	int v=max(2*n,2*m);
	rep(i,1,v)
		if (a[i]&&b[i]){
			int t=b[i]-a[i],d=max((t+n-1)/n,0); 
			int g=gcd(n,m); if (t%g){ a[i]=b[i]=0; continue; }
			int p=n/g; q[i]=m/g; t/=g; int y; exgcd(p,q[i],x[i],y);
			x[i]=((ll)t*x[i]%q[i]+q[i])%q[i];
			l0[i]=max(0,(d-x[i]+q[i]-1)/q[i]);
		}
	ll l=1,r=1e18;
	while (l<=r){
		ll mid=l+r>>1,s=0;
		rep(i,1,v)
			if (a[i]&&b[i]){
				ll u=a[i]<=mid?(mid-a[i])/n:-1,r0=x[i]<=u?(u-x[i])/q[i]:-1;
				if (l0[i]<=r0){ s+=r0-l0[i]+1; if (mid-s<k) break; }
			}
		if (mid-s>=k) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);
 	return 0;
}
/*
2 4 10
3 4
1 2 3 4
*/