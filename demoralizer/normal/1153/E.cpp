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

int query(int x1,int y1,int x2,int y2){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int x;
	cin >> x;
	x %= 2;
	return x;
}

void solve(){
	int n;
	cin >> n;
	vector<int> odd_rows;
	rep(i,1,n){
		if(query(i,1,i,n)){
			odd_rows.pb(i);
		}
	}
	if(sz(odd_rows) == 1) odd_rows.pb(n);
	vector<int> odd_cols;
	rep(i,1,n){
		if(query(1,i,n,i)){
			odd_cols.pb(i);		}
	}
	if(sz(odd_cols) == 1) odd_cols.pb(n);
	
	vector<int> points;
	
	if(sz(odd_rows) == 2){
		for(int r:odd_rows){
			points.pb(r);
			int L = 1, U = n;
			while(L < U){
				int m = (L + U) / 2;
				if(query(r,L,r,m)){
					U = m;
				}
				else{
					L = m + 1;
				}
			}
			points.pb(L);
		}
	}
	else{
		for(int c:odd_cols){
			int L = 1, U = n;
			while(L < U){
				int m = (L + U) / 2;
				if(query(L,c,m,c)){
					U = m;
				}
				else{
					L = m + 1;
				}
			}
			points.pb(L);
			points.pb(c);
		}
	}
	cout << "!";
	for(int x:points){
		cout << " " << x;
	}
	cout << endl;
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