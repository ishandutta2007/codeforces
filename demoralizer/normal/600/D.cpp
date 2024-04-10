#include <bits/stdc++.h>
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

#define double long double

const double pi = 3.14159265359;

void solve(){
	cout<<setprecision(17);
	cout<<fixed;
	int X,Y,R,x,y,r;
	cin>>X>>Y>>R>>x>>y>>r;
	if(R<r){
		swap(r,R);
		swap(x,X);
		swap(y,Y);
	}
	double k=sqrt((X-x)*(X-x) + (Y-y)*(Y-y));
	if(k >= r+R){
		cout<<0.0;
		return;
	}
	
	if(k <= R - r){
		cout<<r*r*pi;
		return;
	}
	
	double D = (k*k + R*R - r*r)/(2*k) , d = k - D;
	double l = sqrt(r*r - d*d);
	double tR = 2*asin(l/R);
	double tr = 2*asin(l/r);
	double A = R*R*tR/2 - l*D;
	double a = r*r*tr/2 - l*d;
	if(d < 0){
		a = r*r*(2*pi - tr)/2 - l*d;
	}
	
	// cout<<k<<" "<<l<<"\n";
	// cout<<D<<" "<<d<<"\n";
	// cout<<tR<<" "<<tr<<"\n";
	
	cout<<A+a;
	
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