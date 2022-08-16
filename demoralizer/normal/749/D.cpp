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

vector<int> b[N];

int mx[N];
map<int, int> btop;

vector<int> bids;

void solve(){
	int n;
	cin>>n;
	
	rep(i,1,n+1){
		b[i].pb(0);
	}
	
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		b[x].pb(y);
		mx[x]=y;
	}
	rep(i,1,n+1){
		btop[mx[i]]=i;
		bids.pb(mx[i]);
	}
	btop[0]=0;
	sort(all(bids),greater<int>());
	uniq(bids);
	
	int q;
	cin>>q;
	rep(i,0,q){
		int k;
		cin>>k;
		vector<int> rem;
		rep(i,0,k){
			int x;
			cin>>x;
			rem.pb(mx[x]);
		}
		sort(all(rem),greater<int>());
		uniq(rem);
		if(sz(rem) == sz(bids)){
			cout<<"0 0\n";
			continue;
		}
		int L=0,U=sz(rem)-1,ans=sz(rem);
		while(L<=U){
			int m=(L+U)/2;
			if(bids[m]!=rem[m]){
				ans=m;
				U=m-1;
			}
			else{
				L=m+1;
			}
		}
		
		if(bids[ans]==0){
			cout<<"0 0\n";
			continue;
		}
		
		int p=btop[bids[ans]];
		rem.pb(bids[ans]);
		sort(all(rem),greater<int>());
		if(sz(rem) == sz(bids)){
			cout<<p<<" "<<b[p][1]<<"\n";
			continue;
		}
		L=0,U=sz(rem)-1,ans=sz(rem);
		while(L<=U){
			int m=(L+U)/2;
			if(bids[m]!=rem[m]){
				ans=m;
				U=m-1;
			}
			else{
				L=m+1;
			}
		}
		int smx=bids[ans];
		int bid = *upper_bound(all(b[p]),smx);
		cout<<p<<" "<<bid<<"\n";
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