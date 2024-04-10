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

const int N=5005;

#define double long double

int x[N], y[N];
const double EPS = 1e-10;

double dist(double x1,double y1, double x2, double y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool check(int a,int b,int c){
	double h = (x[a] + x[c]) / 2.0;
	double k = (y[a] + y[c]) / 2.0;
	
	double t1 = dist(h,k,x[a],y[a]);
	double t2 = dist(h,k,x[b],y[b]);
	
	
	// cout << t1 << " " << t2;;
	if(t2 - t1 > EPS){
		return 1;
	}
	return 0;
}

void solve(){
	int n;
	cin >> n;
	vector<int> pts;
	int l = 0;
	
	
	
	rep(i,1,n+1){
		cin >> x[i] >> y[i];
		if(i < 3){
			pts.pb(i);
			l++;
			continue;
		}
		
		pts.pb(i);
		bool done = 0;
		for(int z = l; z >= 2; z--){
			if(check(pts[z-2],pts[z-1],pts[z])){
				done = 1;
				break;
			}
			else{
				swap(pts[z-1],pts[z]);
			}
		}
		l++;
		// assert(done);
	}
	for(int x:pts){
		cout << x << " ";
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