#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6; mt19937 rnd(time(0)); 
int cnt[N],id[N]; ll a[N];
int count(ll x){ int c=0; while (x) c+=x&1,x>>=1; return c; }
int main(){
	srand(time(0));
	int n,m,p; scanf("%d%d%d",&n,&m,&p);
	rep(i,1,n){
		char s[N]; scanf("%s",s);
		rep(j,1,m) if (s[j-1]-'0') a[i]|=1LL<<j-1;
	}
	ll ans=0;
	rep(c,1,50){
		int u=rnd()%n+1,t=0;
		rep(j,1,m) if (a[u]>>j-1&1) id[++t]=j;
		rep(s,0,(1<<t)-1) cnt[s]=0;
		rep(i,1,n){
			int s=0;
			rep(j,1,t) if (a[i]>>id[j]-1&1) s|=1<<j-1;
			++cnt[s];
		}
		rep(i,1,t)
			rep(s,1,(1<<t)-1)
				if (!(s>>i-1&1)) cnt[s]+=cnt[s^(1<<i-1)];
		rep(s,1,(1<<t)-1)
			if (cnt[s]>=(n+1)/2&&count(s)>count(ans)){
				ans=0; rep(i,1,t) if (s>>i-1&1) ans|=1LL<<id[i]-1;
			}
	}
	rep(i,1,m) printf("%lld",ans>>i-1&1);
	return 0;
}