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



void solve(){
	int a,b,k;
	cin >> a >> b >> k;
	
	
	if(k == 0){
		cout << "Yes\n";
		rep(z,0,2){
			rep(i,0,b){
				cout << "1";
			}
			rep(i,0,a){
				cout << "0";
			}
			cout << "\n";
		}
		return;
	}
	b--;
	
	// max = a + b - 1
	if(k > a + b - 1 || b == 0 || a == 0){
		cout << "No";
		return;
	}
	
	string x,y;
	x.pb('1');
	y.pb('1');
	cout << "Yes\n";
	
	
	while(k < a + b - 1 && b > 1){
		x.pb('1');
		y.pb('1');
		b--;
	}
	
	int extra = (a + b - 1) - k;
	
	a = k + 1 - b;
	// cout << b << " " << extra << " " << a <<"\n";
	x.pb('1');
	y.pb('0');
	
	rep(i,0,b-1){
		x.pb('1');
		y.pb('1');
	}
	
	rep(i,0,a-1){
		x.pb('0');
		y.pb('0');
	}
	
	
	x.pb('0');
	y.pb('1');
	
	rep(i,0,extra){
		x.pb('0');
		y.pb('0');
	}
	
	cout << x << "\n" << y << "\n";
	
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