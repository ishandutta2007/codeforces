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

const int N=10002;

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	int A[maxn];
	int query(int i){
		int sum = 0;
		while (i > 0) 
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, int k){
		if(i<1)return;
		while (i < maxn) 
			A[i] += k, i += LSB(i);
	}
	void rupd(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
}fenw;

void solve(){
	int n;
	cin >> n;
	
	vector<pair<pii, int>> h,v;
	
	rep(i,0,n){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 5001;
		x2 += 5001;
		y1 += 5001;
		y2 += 5001;
		if(y1 > y2) swap(y1,y2);
		if(x1 > x2) swap(x1,x2);
		if(x1 == x2){
			h.pb({{y1,y2},x1});
		}
		else{
			v.pb({{x1,x2},y1});
		}
	}
	
	sort(all(v),[&](pair<pii, int> a,pair<pii, int> b){
		return a.fr.sc < b.fr.sc;
	});
	sort(all(h),[&](pair<pii, int> a,pair<pii, int> b){
		return a.sc < b.sc;
	});
	
	long long ans = 0;
	
	int a = sz(h), b = sz(v);
	rep(i,0,a){
		int k = b - 1;
		int x1 = h[i].sc;
		for(int j = a - 1; j > i; j--){
			int x2 = h[j].sc;
			int y1 = max(h[i].fr.fr,h[j].fr.fr);
			int y2 = min(h[i].fr.sc,h[j].fr.sc);
			if(y2 < y1) continue;
			while(k >= 0 && v[k].fr.sc >= x2){
				if(v[k].fr.fr <= x1){
					fenw.update(v[k].sc,1);
				}
				k--;
			}
			int tmp = fenw.query(y2) - fenw.query(y1-1);
			ans += 1ll * tmp * (tmp - 1) / 2;
		}
		mem0(fenw.A);
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