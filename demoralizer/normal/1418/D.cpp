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

const int N=1e5+5;

int p[N];

void solve(){
	int n,q;
	cin >> n >> q;
	rep(i,0,n){
		cin >> p[i];
	}
	sort(p,p+n);
	set<int> s(p,p+n);
	multiset<int,greater<int> > z;
	rep(i,1,n){
		int val = p[i] - p[i-1];
		z.insert(val);
	}
	
	z.insert(0);
	
	int tot = p[n-1] - p[0];
	cout << tot - *z.begin() << "\n";
	
	while(q--){
		int t,x;
		cin >> t >> x;
		if(t == 0){
			s.erase(x);
			auto it = s.upper_bound(x);
			if(it != s.end()){
				z.erase(z.find(*it - x));
			}
			if(it != s.begin()){
				it--;
				z.erase(z.find(x - *it));
				int tmp = *it;
				it++;
				if(it != s.end()){
					z.insert(*it - tmp);
				}
			}
		}
		else{
			auto it = s.upper_bound(x);
			if(it != s.end()){
				z.insert(*it - x);
			}
			if(it != s.begin()){
				it--;
				z.insert(x - *it);
				int tmp = *it;
				it++;
				if(it != s.end()){
					z.erase(z.find(*it - tmp));
				}
			}
			s.insert(x);
		}
		
		tot = 0;
		if(sz(s)){
			tot = *s.rbegin() - *s.begin();
		}
		
		cout << tot - *z.begin() << "\n";
		
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