#include "bits/stdc++.h"
using namespace std;
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

const int N=1e6+5;

int n,m,k;
bool check(vector<int> &f){
	int day = 0;
	while(1){
		rep(i,day*k,(day+1)*k){
			if(i == sz(f)) return 1;
			if(f[i] < day) return 0;
		}
		day++;
	}
	return 1;
}

void solve(){
	cin>>n>>m>>k;
	vector<int> f(n);
	rep(i,0,n)cin>>f[i];
	sort(all(f));
	if(!check(f)){
		cout<<-1;
		return;
	}
	vector<pii> s(m);
	rep(i,0,m){
		cin>>s[i].fr;
		s[i].sc = i+1;
	}
	sort(all(s),greater<pii>());
	int L = 0, U = m, ans;
	while(L <= U){
		int mid = (L+U)/2;
		vector<int> v;
		
		int a = 0, b = mid-1;
		while(a<n && b>=0){
			if(f[a] < s[b].fr){
				v.pb(f[a++]);
			}
			else{
				v.pb(s[b--].fr);
			}
		}
		while(a<n){
			v.pb(f[a++]);
		}
		while(b>=0){
			v.pb(s[b--].fr);
		}
		
		if(check(v)){
			ans = mid;
			L = mid+1;
		}
		else{
			U = mid-1;
		}
	}
	cout<<ans<<"\n";
	rep(i,0,ans){
		cout<<s[i].sc<<" ";
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