#include <bits/stdc++.h>
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

const int N=1e5+5;

int g[N],a[N],b[N];

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	int s=0;
	rep(i,0,n){
		cin>>a[i];
		if(i%2==0){
			s+=a[i];
		}
		else{
			s-=a[i];
		}
	}
	int t=0;
	rep(i,0,m){
		cin>>b[i];
		if(i>=n)continue;
		if(i%2==0){
			t+=b[i];
		}
		else{
			t-=b[i];
		}
	}
	set<int> f;
	rep(i,0,m-n+1){
		g[i]=s - t;
		t -= b[i];
		t *= -1;
		if(n%2){
			t += b[i+n];
		}
		else{
			t -= b[i+n];
		}
		f.insert(g[i]);
	}
	int tot = 0;
	rep(i,0,q+1){
		int ans = INF;
		auto it = f.lower_bound(-tot);
		if(it != f.end()){
			amin(ans,*it + tot);
		}
		if(it != f.begin()){
			it--;
			amin(ans,- tot - *it);
		}
		cout<<ans<<"\n";
		if(i<q){
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			if((r-l+1)%2){
				if(l%2) tot -= x;
				else tot += x;
			}
		}
	}
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