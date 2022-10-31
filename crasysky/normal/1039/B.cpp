#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6; mt19937 rnd(time(0));
int query(ll l,ll r){
	cout<<l<<" "<<r<<endl;
	fflush(stdout);
	char s[10]; scanf("%s",s);
	return s[0]=='Y';
}
int main(){
	ll n; int k; scanf("%lld%d",&n,&k);
	ll l=1,r=n;
	while (true){
		while (r-l>50){
			ll m=l+r>>1;
			if (query(l,m)) l=max(1LL,l-k),r=min(n,m+k);
			else l=max(1LL,m+1-k),r=min(n,r+k);
		}
		ll x=rnd()%(r-l+1)+l;
		if (query(x,x)) return 0;
		l=max(1LL,l-k),r=min(n,r+k);
	}
	return 0;
}