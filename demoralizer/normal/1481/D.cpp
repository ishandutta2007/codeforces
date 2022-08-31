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
	int n,m;
	cin >> n >> m;
	string s[n];
	rep(i,0,n){
		cin >> s[i];
	}
	
	rep(i,0,n){
		rep(j,0,n){
			if(i == j) continue;
			if(s[i][j] == s[j][i]){
				cout << "YES\n";
				rep(k,0,m+1){
					if(k%2) cout << i + 1 << " ";
					else cout << j + 1 << " ";
				}
				cout << "\n";
				return;
			}
		}
	}
	
	if(m % 2){
		cout << "YES\n";
		rep(k,0,m+1){
			cout << ((k % 2) + 1) << " ";
		}
		cout << "\n";
		return;
	}
	
	// x -a-> y, y -b->x and m is even
	
	if(n == 2){
		cout << "NO\n";
		return;
	}
	
	
	vector<int> perm = {0,1,2};
	do{
		int x = perm[0], y = perm[1], z = perm[2];
		if(s[x][y] == s[y][z]){
			x++;
			y++;
			z++;
			cout << "YES\n";
			
			if(m % 4 == 0){
				// 2b's
				rep(k,0,m/2){
					if(k % 2 == 0) cout << y << " ";
					else cout << z << " ";
				}
				cout << y << " ";
				rep(k,0,m/2){
					if(k % 2 == 0) cout << x << " ";
					else cout << y << " ";
				}
			}
			else{
				// 2a's
				rep(k,0,m/2){
					if(k % 2 == 0) cout << x << " ";
					else cout << y << " ";
				}
				cout << y << " ";
				rep(k,0,m/2){
					if(k % 2 == 0) cout << z << " ";
					else cout << y << " ";
				}
			}
			
			cout << "\n";
			return;
		}
	}while(next_permutation(all(perm)));
	
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