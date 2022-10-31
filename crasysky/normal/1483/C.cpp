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
using namespace std;
const int N=1e6+6; const ll INF=1e18;
int h[N],b[N],st[N]; ll dp[N],mx[N]; multiset<ll> s;
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&h[i]);
	rep(i,1,n) scanf("%d",&b[i]);
	s.clear(); int tp=0;
	rep(i,1,n){
		dp[i]=-INF; ll v=dp[i-1];
		while (tp&&h[st[tp]]>h[i]){
			v=max(v,mx[tp]);
			s.erase(s.find(mx[tp]+b[st[tp]]));
			--tp;
		}
		if (s.size()){ multiset<ll>::iterator it=s.end(); dp[i]=*--it; }
		dp[i]=max(dp[i],v+b[i]),st[++tp]=i,mx[tp]=v,s.insert(mx[tp]+b[i]);
	}
	printf("%lld\n",dp[n]);
 	return 0;
}