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

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int v,t;
	cin>>v>>t;
	int vx,vy,wx,wy;
	cin>>vx>>vy>>wx>>wy;
	double L = 0, U = 10000 * dist(x1,y1,x2,y2);
	rep(i,0,80){
		double m = (L+U)/2;
		double x = x1, y = y1;
		if(m>t){
			x += vx*t + wx*(m-t);
			y += vy*t + wy*(m-t);
		}
		else{
			x += vx*m;
			y += vy*m;
		}
		double d = dist(x,y,x2,y2);
		double tim = d / v;
		if(tim <= m){
			U = m;
		}
		else{
			L = m;
		}
	}
	cout<<setprecision(18);
	cout<<fixed;
	cout<<L;
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