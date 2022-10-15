#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 200100

ll N,E,T,Q,a,b,c,d,e,f;
ll A[MAXN], B[MAXN];
ll G[3][MAXN];

ll x,y,ax,ay,bx,by,cx,cy;
ll D(ll i, ll j){
	if (i == -1){
		return abs(cx - A[j]) + abs(cy - B[j]);
	}else{
		return abs(A[i] - A[j]) + abs(B[i] - B[j]);
	}
}
int main(){
	cin>>x>>y>>ax>>ay>>bx>>by>>cx>>cy>>T;
	A[0]=x;B[0]=y;
	for (ll i=1;i <= 100;++i){
		if (A[i-1]+B[i-1] > 4*1e16){N = i-1;break;}
		A[i] = A[i-1] * ax + bx;
		B[i] = B[i-1] * ay + by;
	}
	ll ans = 0;
	for (ll s=0;s<=N;++s){
		for (ll e=0;e<=N;++e){
			ll l = (e-s+1);
			if (l<=ans)continue;
			for (ll st = s;st <=e;++st){
				ll t = D(-1,st);
				// Go to s first
				ll k = st;
				while (k > s){
					t += D(k,k-1);
					--k;
				}
				while (k < e){
					t += D(k,k+1);
					++k;
				}
				if (t <= T)ans = max(ans, l);
				t = D(-1,st);
				k = st;
				while (k < e){
					t += D(k,k+1);
					++k;
				}
				while (k > s){
					t += D(k,k-1);
					--k;
				}
				if (t <= T)ans = max(ans, l);
			}
		}
	}
	cout<<ans;
}