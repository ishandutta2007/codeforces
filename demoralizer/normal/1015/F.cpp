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

const int N=205;

int n;
int len;
string s;
int p[N][2];
int dp[N][N][N][2];

int calc(int id,int cp,int bal,int found){
	if(bal < 0){
		return 0;
	}
	if(found == 0 && cp == len){
		return calc(id,cp,bal,1);
	}
	if(id == 2 * n){
		if(found && bal == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	int &ans = dp[id][cp][bal][found];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	if(found){
		ans += calc(id+1,cp,bal+1,1);
		ans += calc(id+1,cp,bal-1,1);
		ans %= M;
		return ans;
	}
	ans += calc(id+1,p[cp][0],bal+1,0);
	ans += calc(id+1,p[cp][1],bal-1,0);
	ans %= M;
	return ans;
}

void solve(){
	mem1(dp);
	cin >> n >> s;
	p[0][0] = p[0][1] = 0;
	if(s[0] == '(') p[0][0] = 1;
	else p[0][1] = 1;
	
	len = sz(s);
	
	rep(i,1,len){
		for(int j = i+1; j > 0; j--){
			bool ok = 1;
			rep(k,0,j - 1){
				if(s[k] != s[k+i-j+1]){
					ok = 0;
				}
			}
			if(ok && s[j - 1] == '('){
				p[i][0] = j;
				break;
			}
		}
	}
	// rep(i,0,len){
	// 	cout << p[i][0] << " ";
	// }
	// cout << "\n";
	rep(i,1,len){
		for(int j = i+1; j > 0; j--){
			bool ok = 1;
			rep(k,0,j - 1){
				if(s[k] != s[k+i-j+1]){
					ok = 0;
				}
			}
			if(ok && s[j - 1] == ')'){
				p[i][1] = j;
				break;
			}
		}
		// cout << p[i][1] << " ";
	}
	// cout << "\n";
	// rep(i,0,len){
	// 	cout << p[i][1] << " ";
	// }
	cout << calc(0,0,0,0);
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