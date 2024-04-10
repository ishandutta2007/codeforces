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

const int N=5e5+5;

int ONE = 1;
int DIRECTION = 1; // 1 - right, 0 - left
set<pii> s;
int trans(int x){
	x--;
	if(DIRECTION) return ONE + x;
	return ONE - x;
}
void insert_range(int l,int r){
	l = trans(l);
	r = trans(r);
	if(r < l) swap(l,r);
	s.insert({l,r});
}
void insert_element(int x){
	insert_range(x,x);
}
bool find_element(int x){
	// cout << x << "\n";
	x = trans(x);
	// cout << x << "\n";
	auto it = s.upper_bound({x,INF});
	if(it == s.begin()) return 0;
	it--;
	return (it->fr <= x && it->sc >= x);
}
void wipe(int l,int r){ // wipe outside [l....r]
	l = trans(l);
	r = trans(r);
	if(r < l) swap(l,r);
	while(sz(s) && s.begin()->fr < l){
		pii tmp = *s.begin();
		s.erase(tmp);
		if(tmp.sc >= l){
			s.insert({l,tmp.sc});
		}
	}
	while(sz(s) && s.rbegin()->sc > r){
		pii tmp = *s.rbegin();
		s.erase(tmp);
		if(tmp.fr <= r){
			s.insert({tmp.fr,r});
		}
	}
}

int a[N];

void solve(int test){
	int n;
	cin >> n;
	
	int mn = 0;
	rep(i,0,n){
		// cout << ONE << " ONE\n";
		// for(pii x: s) cout << x << " | ";
		// 	cout << "\n";
		cin >> a[i];
		if(i){
			ONE = trans(a[i] - 1);
			DIRECTION ^= 1;
		}
		
		if(a[i] % 2 == 0 && find_element(a[i] / 2)){
			s.clear();
			insert_element(a[i] / 2);
			continue;
		}
		wipe(1,a[i]-1);
		
		if(s.empty()){
			ONE = 1;
			DIRECTION = 1;
			if(a[i] % 2 == 0){
				insert_element(a[i]/2);
				mn++;
			}
			else{
				insert_range(1,a[i]-1);
				mn+=2;
			}
			// cout << mn << "\n";
			continue;
		}
		
		mn++;
			// cout << mn << "\n";
		// ONE = trans(a[i] - 1);
		// DIRECTION ^= 1;
		if(a[i] % 2 == 0) insert_element(a[i] / 2);
	}
	// cout << sz(s);
	cout << mn << "\n";
	// if(test == 19) {rep(i,0,n) cout << a[i] << " ";cout << "\n";}
	s.clear();
	ONE = 1;
	DIRECTION = 1;
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
	int t=1,c=1;
	cin>>t;
	while(t--) solve(c++);
	return 0;
}