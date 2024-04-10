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

struct pt {
	int x, y;
};

bool cmp(pt a, pt b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
	if (a.size() == 1)
		return;

	sort(a.begin(), a.end(), &cmp);
	vector<pt> a2;
	for(auto z:a){
		if(sz(a2) && a2.back().x == z.x) continue;
		a2.pb(z);
	}
	a = a2;
	pt p1 = a[0], p2 = a.back();
	vector<pt> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i = 1; i < (int)a.size(); i++) {
		if (i == a.size() - 1 || cw(p1, a[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
			while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}

	// a.clear();
	// for (int i = 0; i < (int)up.size(); i++)
	// 	a.push_back(up[i]);
	// for (int i = down.size() - 2; i > 0; i--)
	// 	a.push_back(down[i]);
	
	// for(auto z:a){
	// 	cout << "(" << z.x << "," << z.y << ")\n";
	// }
	a = down;
}

void solve(){
	int n;
	cin >> n;
	
	vector<pt> v;
	rep(i,0,n){
		pii p;
		cin >> p;
		p.sc = p.fr * p.fr - p.sc;
		v.pb({p.fr, p.sc});
	}
	
	convex_hull(v);
	
	cout << sz(v) - 1;
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