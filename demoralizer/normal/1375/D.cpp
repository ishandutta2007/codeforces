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

const int N=1005;

int a[N];
int freq[N];

set<int> s;
set<int> unvis;

void solve(){
	s.clear();
	unvis.clear();
	int n;
	cin>>n;
	rep(i,0,n+1){
		s.insert(i);
		freq[i] = 0;
	}
	rep(i,0,n){
		unvis.insert(i);
		cin>>a[i];
		s.erase(a[i]);
		freq[a[i]]++;
	}
	
	vector<int> x;
	while(sz(unvis)){
		assert(sz(s));
		int mex = *s.begin();
		if(mex!=n){
			x.pb(mex);
			freq[mex]++;
			freq[a[mex]]--;
			if(!freq[a[mex]]){
				s.insert(a[mex]);
			}
			a[mex] = mex;
			s.erase(mex);
			unvis.erase(mex);
		}
		else{
			int z = *unvis.begin();
			x.pb(z);
			freq[a[z]]--;
			if(!freq[a[z]]){
				s.insert(a[z]);
			}
			freq[n]++;
			a[z] = n;
			s.erase(n);
		}
	}
	cout<<sz(x)<<"\n";
	for(int z:x) cout<<z+1<<" ";
	cout<<"\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}