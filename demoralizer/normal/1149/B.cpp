#include "bits/stdc++.h"
using namespace std;
// #define int               long long
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

const int N=252;

int lb[100005][26];
int dp[N][N][N];

string a,b,c;

void solve(){
	int n,q;
	string s;
	cin >> n >> q >> s;
	rep(c,0,26){
		lb[n][c] = n;
		lb[n+1][c] = n;
		for(int i = n - 1; i >= 0; i--){
			lb[i][c] = lb[i+1][c];
			if(s[i] == 'a' + c){
				lb[i][c] = i;
			}
		}
	}
	
	dp[0][0][0] = -1;
	
	rep(z,0,q){
		string choice;
		int i;
		cin >> choice >> i;
		if(choice == "+"){
			string tmp;
			cin >> tmp;
			char ch = tmp[0];
			if(i == 1){
				a.pb(ch);
				int x = sz(a);
				rep(p,0,sz(b)+1){
					rep(q,0,sz(c)+1){
						dp[x][p][q] = lb[dp[x-1][p][q]+1][a[x-1]-'a'];
						if(p)
							amin(dp[x][p][q],lb[dp[x][p-1][q]+1][b[p-1]-'a']);
						if(q)
							amin(dp[x][p][q],lb[dp[x][p][q-1]+1][c[q-1]-'a']);
					}
				}
			}
			else if(i == 2){
				b.pb(ch);
				int x = sz(b);
				rep(p,0,sz(a)+1){
					rep(q,0,sz(c)+1){
						dp[p][x][q] = lb[dp[p][x-1][q]+1][b[x-1]-'a'];
						if(p)
							amin(dp[p][x][q],lb[dp[p-1][x][q]+1][a[p-1]-'a']);
						if(q)
							amin(dp[p][x][q],lb[dp[p][x][q-1]+1][c[q-1]-'a']);
					}
				}
			}
			else{
				c.pb(ch);
				int x = sz(c);
				rep(p,0,sz(a)+1){
					rep(q,0,sz(b)+1){
						dp[p][q][x] = lb[dp[p][q][x-1]+1][c[x-1]-'a'];
						if(p)
							amin(dp[p][q][x],lb[dp[p-1][q][x]+1][a[p-1]-'a']);
						if(q)
							amin(dp[p][q][x],lb[dp[p][q-1][x]+1][b[q-1]-'a']);
					}
				}
			}
		}
		else{
			if(i == 1){
				a.ppb();
			}
			else if(i == 2){
				b.ppb();
			}
			else{
				c.ppb();
			}
		}
		int ans = dp[sz(a)][sz(b)][sz(c)];
		if(ans < n){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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
	//cin>>t;
	while(t--) solve();
	return 0;
}