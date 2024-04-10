#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)
#define pa pair<ll,ll> 
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define N 200050
ll n,m,s;
vector<ll>G[N];
ll pre[N];
inline ll read()
{
	ll x = 0, f = 1;
	char ch = 0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-48;
	return x*f;	
}
ll ask(ll p, ll q)
{
	printf("SCAN %lld %lld\n", p, q);
	fflush(stdout);
	ll x; scanf("%lld",&x);
	return x;	
}

vector<pair<pa,pa> > ans;
int main(){
	for(ll T=read();T--;){
		n=read();	m=read();
		ll a,b,c,d;
		a = ask(1,1)+4;
		b = ask(n,1)-2*n+2;
		ll px = a-b>>1, py = a+b>>1;
		c = ask(px/2, 1)-py+2;
		
		d = ask(1, py/2)-px+2;
	//	px>>=1, py>>=1;
	//	cerr<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
		ans.clear();
		ans.pb(mk(mk(px+c>>1, py+d>>1), mk(px-c>>1, py-d>>1)));
		ans.pb(mk(mk(px+c>>1, py-d>>1), mk(px-c>>1, py+d>>1)));
		For(i, 0, 1)
		{
			printf("DIG %lld %lld\n", ans[i].fi.fi, ans[i].fi.se);
			fflush(stdout);
			ll x; scanf("%lld",&x);
			if(!x) continue;
			else
			 {
			 	printf("DIG %lld %lld\n",ans[i].se.fi, ans[i].se.se);
				 		fflush(stdout);
			ll x; scanf("%lld",&x);
				 
			break;}
		}
	}
}