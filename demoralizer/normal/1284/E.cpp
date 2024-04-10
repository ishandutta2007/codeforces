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
#define x                 fr
#define sc                second
#define y                 sc
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

const double pi = 3.1415926;

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
pii operator- (const pii& a, const pii& b){
	return {a.x-b.x,a.y-b.y};
}
pii operator~ (const pii& a){
	return {-a.x,-a.y};
}


const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

using point = pii;

int c3(int n){
	return n * (n - 1) * (n - 2) / 6;
}
int c4(int n){
	return c3(n) * (n - 3) / 4;
}

inline bool up (point p) {
	return p.y > 0 or (p.y == 0 and p.x >= 0);
}

bool cmp(point a, point b) {
	return up(a) == up(b) ? a.x * b.y > a.y * b.x : up(a) < up(b);
}

int cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}

int get(vector<pii> &v){
	int ans = 0;
	sort(all(v),cmp);
	int n = sz(v);
	rep(i,0,n){
		v.pb(v[i]);
	}
	
	int r = 1;
	rep(i,0,n){
		while(r < i + n && cross(v[r],~v[i]) >= 0){
			r++;
		}
		ans += c3(r - i - 1);
	}
	return c4(n) - ans;
}

void solve(){
	int n;
	cin >> n;
	vector<pii> v(n);
	rep(i,0,n){
		cin >> v[i];
	}
	
	int pr = 0;
	rep(j,0,n){
		vector<pii> z;
		rep(i,0,n){
			if(i == j) continue;
			z.pb(v[i] - v[j]);
		}
		pr += get(z);
	}
	cout << pr;
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