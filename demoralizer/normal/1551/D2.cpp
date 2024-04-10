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
	int s = 0;
	int n,m,k;
	cin >> n >> m >> k;
	if(m % 2){
		k = n * m / 2 - k;
		swap(n,m);
		s = 1;
	}
	if(n % 2){
		k -= m / 2;
		if(k < 0 || k % 2){
			cout << "NO\n";
			return;
		}
		else{
			cout << "YES\n";
		}
	}
	else{
		if(k % 2){
			cout << "NO\n";
			return;
		}
		else{
			cout << "YES\n";
		}
	}
	
	vector<vector<char>> v(n, vector<char>(m));
	if(n%2){
		rep(z,0,m/2){
			v[n - 1][2 * z] = v[n - 1][2 * z + 1] = 'y' + (z % 2);
		}
	}
	rep(i,0,n/2){
		rep(j,0,m/2){
			if(k){
				v[2 * i][2 * j] = v[2 * i][2 * j + 1] = 'a' + (j % 2);
				v[2 * i + 1][2 * j] = v[2 * i + 1][2 * j + 1] = 'd' + (j % 2);
				k-=2;
			}
			else{
				v[2 * i][2 * j] = v[2 * i + 1][2 * j] = 'h' + (i % 2);
				v[2 * i][2 * j + 1] = v[2 * i + 1][2 * j + 1] = 'p' + (i % 2);
			}
		}
	}
	
	if(s){
		rep(j,0,m){
			rep(i,0,n){
				cout << v[i][j];
			}
			cout << "\n";
		}
	}
	else{
		rep(i,0,n){
			rep(j,0,m){
				cout << v[i][j];
			}
			cout << "\n";
		}
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
	cin>>t;
	while(t--) solve();
	return 0;
}