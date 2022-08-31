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

#define double long double

int far;
int d1, d2;
int x[N],y[N];

int dist(int x,int y){
	return x * x + y * y;
}
int ans = 0;
double dist(double x1,double y1,double x2,double y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double sqdis(double x1,double y1,double x2,double y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

const double EPS = 1e-8;

void calc(int x1,int y1,int x2,int y2){
	// cout << x1 << " "<< y1 << " " << x2 << " " << y2 << "\n";
	int a = x2 - x1;
	int b = y2 - y1;
	// ax + by = 0
	double x = 1.0 * (b * b * x1 - a * b * y1) / (a * a + b * b);
	double y = 1.0 * (a * a * y1 - a * b * x1) / (a * a + b * b);
	
	double d;
	if(sqdis(x1,y1,x,y) + sqdis(x,y,x2,y2) - sqdis(x1,y1,x2,y2) < EPS){
		d = dist(0,0,x,y);
	}
	else{
		d = dist(0,0,x2,y2);
	}
	if(d <= d1 && far){
		far = 0;
		ans++;
	}
	
}

void solve(){
	far = 1;
	int n;
	cin >> n;
	cin >> d1 >> d2;
	d1 *= d1;
	d2 *= d2;
	
	rep(i,0,n){
		int a,b;
		cin >> a >> b;
		x[i] += a;
		y[i] += b;
		cin >> a >> b;
		x[i] -= a;
		y[i] -= b;
	}
	
	if(dist(x[0],y[0]) <= d1){
		far = 0;
		ans++;
	}
	
	rep(i,0,n-1){
		if(dist(x[i],y[i]) > d2){
			far = 1;
		}
		calc(x[i],y[i],x[i+1],y[i+1]);
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