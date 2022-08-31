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

const int N=2e5+5;

int dp_thick[N];
int dp_count[N];
int in[N];
int out[N];

void solve(){
	int n;
	cin >> n;
	set<pair<int, pii>> s;
	int mxin = 0;
	rep(i,0,n){
		cin >> out[i] >> in[i];
		amax(mxin, in[i]);
		s.insert({out[i],{0,i}});
		s.insert({in[i],{1,i}});
	}
	
	int thick = 0, count = 1;
	for(auto q:s){
		int x = q.fr;
		int i = q.sc.sc;
		int t = q.sc.fr;
		if(t == 0){
			if(dp_thick[i] > thick){
				thick = dp_thick[i];
				count = 0;
			}
			if(dp_thick[i] == thick){
				count = (count + dp_count[i]) % M;
			}
		}
		else{
			dp_thick[i] = thick + out[i] - in[i];
			dp_count[i] = count;
		}
	}
	
	int best = INF;
	count = 0;
	rep(i,0,n){
		if(out[i] > mxin){
			int space = out[i] - dp_thick[i];
			if(space < best){
				best = space;
				count = 0;
			}
			if(space == best){
				count = (count + dp_count[i]) % M;
			}
		}
	}
	cout << count;
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