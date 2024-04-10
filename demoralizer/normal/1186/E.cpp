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

const int N=1005;

int invert(int x){
	return ppc(x) % 2;
}

int c[N][N];

void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	
	rep(i,1,n+1){
		string s;
		cin >> s;
		rep(j,1,m+1){
			c[i][j] = s[j - 1] - '0';
			c[i][j] += c[i-1][j];
			c[i][j] += c[i][j-1];
			c[i][j] -= c[i-1][j-1];
		}
	}
	
	auto get = [&](int x,int y){
		if(!x || !y) return 0LL;
		int a = x / n;
		int b = y / m;
		
		int ans = a * b / 2 * n * m;
		if(a % 2 && b % 2){
			int inv = invert(a - 1) ^ invert(b - 1);
			if(inv){
				ans += n * m - c[n][m];
			}
			else{
				ans += c[n][m];
			}
		}
		
		int p = x % n;
		int q = y % m;
		
		if(p){
			ans += b / 2 * p * m;
			if(b % 2){
				int inv = invert(a) ^ invert(b - 1);
				if(inv){
					ans += p * m - c[p][m];
				}
				else{
					ans += c[p][m];
				}
			}
		}
		if(q){
			ans += a / 2 * n * q;
			if(a % 2){
				int inv = invert(a - 1) ^ invert(b);
				if(inv){
					ans += n * q - c[n][q];
				}
				else{
					ans += c[n][q];
				}
			}
		}
		if(p && q){
			int inv = invert(a) ^ invert(b);
			if(inv){
				ans += p * q - c[p][q];
			}
			else{
				ans += c[p][q];
			}
		}
		
		return ans;
	};
	
	rep(i,0,q){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int ans = 0;
		ans += get(x2,y2);
		ans -= get(x1-1,y2);
		ans -= get(x2,y1-1);
		ans += get(x1-1,y1-1);
		
		cout << ans << "\n";
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