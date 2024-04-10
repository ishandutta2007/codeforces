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
#define x                 first
#define y                 second
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

using equation = array<int,3>;

equation eqn(pii p,pii q){
	int dx = p.x - q.x;
	int dy = p.y - q.y;
	int c = dx * p.y - dy * p.x;
	return {-dy, dx, c};
}

pii solve_eqn(equation a, equation b){
	if(a[0] == 0){
		swap(a,b);
	}
	if(a[0] == 0){
		return {0,0};
	}
	int p = a[0], q = b[0];
	rep(i,0,3){
		b[i] = p * b[i] - q * a[i];
	}
	if(b[1] == 0){
		return {0,0};
	}
	int y = b[2] / b[1];
	int x = (a[2] - a[1] * y) / a[0];
	return {x,y};
}

int calc(pii a,pii b){
	return 1 + __gcd(abs(a.x - b.x), abs(a.y - b.y));
}

pii a[N];
pii b[N];
equation e[N];

bool on_eq(equation a,pii p){
	return (a[0] * p.x + a[1] * p.y == a[2]);
}

bool on_segment(int i,pii p){
	if(!on_eq(e[i],p)){
		return false;
	}
	vector<int> x = {a[i].x,b[i].x};
	sort(all(x));
	vector<int> y = {a[i].y,b[i].y};
	sort(all(y));
	if(p.x < x[0] || p.x > x[1]){
		return false;
	}
	if(p.y < y[0] || p.y > y[1]){
		return false;
	}
	return true;
}

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	rep(i,0,n){
		cin >> a[i] >> b[i];
		e[i] = eqn(a[i], b[i]);
		
		set<pii> intersection_points;
		ans += calc(a[i],b[i]);
		rep(j,0,i){
			pii p = solve_eqn(e[i],e[j]);
			if(on_segment(j,p) && on_segment(i,p)){
				intersection_points.insert(p);
			}
		}
		ans -= sz(intersection_points);
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