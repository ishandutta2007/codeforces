#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

vector<int> r,p,b;

void solve(){
	int n;
	cin>>n;
	int mxr,mnr,mxp,mnp,mxb,mnb;
	mnr=mxr=mnp=mxp=mnb=mxb=INF;
	rep(i,0,n){
		int x;
		char c;
		cin>>x>>c;
		if(c == 'R'){
			if(mxr==INF) mnr=mxr=x;
			amin(mnr,x);
			amax(mxr,x);
			r.pb(x);
		}
		else if(c == 'P'){
			if(mxp==INF) mnp=mxp=x;
			amin(mnp,x);
			amax(mxp,x);
			if(mxr==INF) mnr=mxr=x;
			amin(mnr,x);
			amax(mxr,x);
			if(mxb==INF) mnb=mxb=x;
			amin(mnb,x);
			amax(mxb,x);
			r.pb(x);
			p.pb(x);
			b.pb(x);
		}
		else{
			if(mxb==INF) mnb=mxb=x;
			amin(mnb,x);
			amax(mxb,x);
			b.pb(x);
		}
	}
	int ans = mxr-mnr + mxb-mnb;
	if(mxp == INF){
		cout << ans;
		return;
	}
	ans = mxr-mxp + mxb-mxp + mnp-mnr + mnp-mnb;
	int z = sz(p);
	rep(i,0,z-1){
		// p[i], p[i+1]
		int tmp = 3 * (p[i+1] - p[i]);
		int tmp2 = 2 * (p[i+1] - p[i]);
		int x = lower_bound(all(r),p[i]) - r.begin(), y = 0;
		while(r[x] != p[i+1]){
			amax(y,r[x+1] - r[x]);
			x++;
		}
		tmp -= y;
		x = lower_bound(all(b),p[i]) - b.begin();
		y = 0;
		while(b[x] != p[i+1]){
			amax(y,b[x+1] - b[x]);
			x++;
		}
		tmp -= y;
		ans += min(tmp,tmp2);
	}
	cout << ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}