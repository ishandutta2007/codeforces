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

const int N=2e5+5;


int l[N],r[N];
int a[N];
int ans[N];

map<int, vector<pii> > mp;
map<int, vector<int> > b;
set<int> c;

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n){
		cin>>l[i]>>r[i];
	}
	rep(i,1,n){
		mp[l[i]-r[i-1]].pb({r[i]-l[i-1],i-1});
		c.insert(l[i]-r[i-1]);
		c.insert(r[i]-l[i-1]);
	}
	rep(i,0,m){
		cin>>a[i];
		b[a[i]].pb(i+1);
		c.insert(a[i]);
	}
	set<pii> o;
	for(int x:c){
		if(mp.count(x)){
			for(pii y:mp[x]){
				o.insert(y);
			}
		}
		if(sz(o) && b.count(x)){
			while(sz(o) && sz(b[x])){
				ans[o.begin()->sc] = b[x].back();
				b[x].ppb();
				o.erase(o.begin());
			}
		}
		if(o.begin()->fr == x){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes\n";
	rep(i,0,n-1){
		cout<<ans[i]<<" ";
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