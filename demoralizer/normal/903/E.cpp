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

const int N=0;



void solve(){
	int k,n;
	cin >> k >> n;
	string s[k];
	rep(i,0,k){
		cin >> s[i];
	}
	
	if(k == 1){
		swap(s[0][0],s[0][1]);
		cout << s[0];
		return;
	}
	
	string a = s[0];
	set<int> ch(all(a));
	bool dis = 0;
	if(sz(ch) == n) dis = 1;
	
	string b = a,c;
	sort(all(b));
	rep(i,1,k){
		c = s[i];
		sort(all(c));
		if(b != c){
			cout << -1;
			return;
		}
	}
	
	bool chn = 0;
	
	rep(i,1,k){
		int cnt = 0;
		rep(j,0,n){
			if(s[i][j] != a[j]) cnt++;
		}
		if(cnt == 2 && dis){
			cout << -1;
			return;
		}
		if(cnt == 2){
			chn = 1;
		}
		if(cnt > 2){
			if(cnt > 4){
				cout << -1;
				return;
			}
			b = s[i];
			vector<int> id,cp;
			rep(j,0,n){
				if(a[j] != b[j]) id.pb(j);
			}
			cp = id;
			
			int d = sz(id);
			do{
				string ans = a;
				rep(z,0,d){
					ans[cp[z]] = a[id[z]];
				}
				
				bool flag = 1;
				rep(z,0,k){
					int ccnt = 0;
					rep(j,0,n){
						if(ans[j] != s[z][j]) ccnt++;
					}
					if(ccnt != 2){
						if(ccnt == 0 && dis == 0);
						else flag = 0;
					}
				}
				
				if(flag){
					cout << ans;
					return;
				}
				
			}while(next_permutation(all(cp)));
			
			cout << -1;
			return;
		}
	}
	
	if(!chn) swap(a[0],a[1]);
	cout << a;
	
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