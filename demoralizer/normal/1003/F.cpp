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

const int N=305;

map<string, int> m;
int cnt = 0;
int z[N][N];

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> l(n);
	
	int pr = n - 1;
	rep(i,0,n){
		string s;
		cin>>s;
		if(!m.count(s)){
			m[s] = cnt++;
		}
		v[i] = m[s];
		l[i] = sz(s);
		pr += l[i];
	}
	
	int ans = 0;
	rep(i,0,n-1){
		rep(j,i+1,n){
			int id = 0;
			while(id + i < j && id + j < n && v[i + id] == v[j + id]){
				id++;
			}
			z[i][j] = id;
		}
	}
	
	rep(i,0,n){
		rep(len,1,n+1-i){
			int mch = 1;
			int j = i + len;
			while(j < n){
				if(z[i][j] >= len){
					mch++;
					j += len;
				}
				else{
					j++;
				}
			}
			if(mch == 1) continue;
			int val = 0;
			rep(x,i,i+len){
				val += l[x];
			}
			val--;
			val *= mch;
			amax(ans,val);
		}
	}
	
	cout << pr - ans;
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