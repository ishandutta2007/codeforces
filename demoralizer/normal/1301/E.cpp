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

const int N=0;



void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	map<char, int> mp;
	mp['R'] = 0;
	mp['G'] = 1;
	mp['Y'] = 2;
	mp['B'] = 3;
	
	vector<vector<vector<int>>> pf(4,vector<vector<int>>(n+1,vector<int>(m+1)));
	vector<vector<vector<int>>> sq(4,vector<vector<int>>(n+2,vector<int>(m+2)));
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,m){
			int val = mp[s[j]];
			pf[val][i + 1][j + 1] = 1;
		}
	}
	
	auto prefix_sum = [&](vector<vector<int>> &pf){
		rep(i,1,n+1){
			rep(j,1,m+1){
				pf[i][j] += pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
			}
		}
	};
	
	rep(z,0,4){
		prefix_sum(pf[z]);
	}
	auto sum = [&](vector<vector<int>> &v, int x, int y, int X, int Y){
		if(X < x || Y < y) return 0;
		return v[X][Y] - v[X][y-1] - v[x-1][Y] + v[x-1][y-1];
	};
	
	auto check = [&](int z, int x, int y, int w){
		// x, y, x + w - 1, y + w - 1
		if(x + w - 1 > n || y + w - 1 > m){
			return false;
		}
		int ans = sum(pf[z], x, y, x+w-1, y+w-1);
		return (ans == w * w);
	};
	
	rep(z,0,4){
		rep(i,1,n+1){
			rep(j,1,m+1){
				int L = 0, U = min(n,m);
				int ans;
				while(L <= U){
					int mid = (L + U) / 2;
					if(check(z,i,j,mid)){
						ans = mid;
						L = mid + 1;
					}
					else{
						U = mid - 1;
					}
				}
				sq[z][i][j] = ans;
			}
		}
	}
	
	vector<int> u;
	vector<vector<int>> v(n+1,vector<int>(m+1));
	rep(i,1,n+1){
		rep(j,1,m+1){
			int tmp = sq[0][i][j];
			if(tmp){
				if(sq[2][i+tmp][j] == tmp && sq[1][i][j+tmp] == tmp && sq[3][i+tmp][j+tmp] >= tmp){
					v[i][j] = 2 * tmp;
					u.pb(2 * tmp);
				}
			}
			// cout << v[i][j] << " ";
		}
		// cout << "\n";
	}
	sort(all(u));
	uniq(u);
	
	vector<vector<vector<int>>> val(sz(u),vector<vector<int>>(n+1,vector<int>(m+1)));
	rep(i,1,n+1){
		rep(j,1,m+1){
			if(v[i][j]){
				int id = lower_bound(all(u),v[i][j]) - u.begin();
				val[id][i][j] = 1;
			}
		}
	}
	
	rep(z,0,sz(u)){
		prefix_sum(val[z]);
	}
	
	while(q--){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		rep(id,0,sz(u)){
			int mid = u[id];
			if(sum(val[id], x1,y1,x2-mid+1,y2-mid+1)){
				amax(ans, mid);
			}
		}
		cout << ans * ans << "\n";
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