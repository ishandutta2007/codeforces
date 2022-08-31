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

const int N=0;

// x1 - y1 * (x2 - x1) / (y2 - y1)

double intersection_point(pii a,pii b){
	return a.fr - a.sc * 1.0 * (b.fr - a.fr) / (b.sc - a.sc);
}

void solve(){
	int a,b,s;
	cin >> s >> a >> b;
	double T = (b - a);
	int n;
	cin >> n;
	vector<pii> v(n);
	vector<int> w(n+1);
	rep(i,0,n){
		cin >> v[i];
	}
	sort(all(v));
	for(int i = n - 1; i >= 0; i--){
		w[i] = v[i].sc - v[i].fr;
		w[i] += w[i + 1];
	}
	int q;
	cin >> q;
	rep(i,0,q){
		int x,y;
		cin >> x >> y;
		double e = intersection_point({a,s},{x,y});
		double f = intersection_point({b,s},{x,y});
		
		double covered = 0;
		
		int l = lower_bound(all(v),e,[&](pii a,double b){
			return a.fr < b;
		}) - v.begin();
		int u = upper_bound(all(v),f,[&](double b,pii a){
			return b < a.sc;
		}) - v.begin();
		if(l <= u){
			covered += w[l] - w[u];
			l--;
			if(l >= 0){
				covered += max(0.0,v[l].sc - e);
			}
			if(u < n){
				covered += max(0.0,f - v[u].fr);
			}
		}
		else{
			covered = f - e;
		}
		
		cout << covered / (f - e) * T << "\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cout<<setprecision(12);
	cout<<fixed;
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}