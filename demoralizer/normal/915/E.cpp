#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

set<pii> s;
void solve(){
	int n,q;
	cin>>n>>q;
	int ans=n;
	s.insert({1,n});
	rep(i,0,q){
		int l,r,k;
		cin>>l>>r>>k;
		pii a={l,0};
		auto it=s.lower_bound(a);
		while(it != s.end() && it->sc <= r){
			ans -= (it->sc - it->fr + 1);
			s.erase(it);
			it=s.lower_bound(a);
		}
		if(it != s.end() && it->fr <= r){
			int tmp=it->sc;
			ans -= (it->sc - it->fr + 1);
			s.erase(it);
			ans += (tmp - r);
			s.insert({r+1,tmp});
		}
		it=s.lower_bound(a);
		if(it != s.begin()){
			it--;
			if(it->sc >= l){
				int tmpl=it->fr;
				int tmpr=it->sc;
				ans -= (it->sc - it->fr + 1);
				s.erase(it);
				ans += (l-tmpl);
				s.insert({tmpl,l-1});
				if(tmpr > r){
					ans += (tmpr-r);
					s.insert({r+1,tmpr});
				}
			}
		}
		if(k==2){
			ans += (r-l+1);
			s.insert({l,r});
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}