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

const int N=3e5+5;

pii x[N];

bool cmp(pii a, pii b){
	if(a.fr == b.fr){
		return a.sc < b.sc;
	}
	return a.fr > b.fr;
}

void solve(){
	int n;
	cin >> n;
	
	rep(i,0,n){
		cin >> x[i];
	}
	
	sort(x+1,x+n,cmp);
	
	int L = 1, U = n;
	int ans = n;
	while(L <= U){
		int m = (L + U) / 2;
		multiset<int> s;
		
		int req = 0;
		int have = x[0].fr;
		
		rep(i,1,m){
			s.insert(x[i].sc - x[i].fr + 1);
		}
		
		bool found = 0;
		
		rep(i,m,n){
			if(req > have){
				break;
			}
			if(have - req >= x[i].fr){
				found = 1;
				break;
			}
			s.insert(x[i].sc - x[i].fr + 1);
			req += *s.begin();
			s.erase(s.begin());
		}
		if(have >= req) found = 1;
		if(found){
			ans = m;
			U = m - 1;
		}
		else{
			L = m + 1;
		}
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