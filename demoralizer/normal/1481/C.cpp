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
	
	vector<int> mxreq(n+1),req(n+1),avail(n+1),a(n+1),b(n+1),c(m);
	
	vector<vector<int>> ids(n+1);
	vector<int> last(n+1);
	
	
	
	rep(i,1,n+1){
		cin >> a[i];
	}
	rep(i,1,n+1){
		cin >> b[i];
		if(b[i] != a[i]){
			req[b[i]]++;
			ids[b[i]].pb(i);
		}
		mxreq[b[i]]++;
		last[b[i]] = i;
	}
	rep(i,0,m){
		cin >> c[i];
		avail[c[i]]++;
	}
	
	rep(i,1,n+1){
		if(avail[i] < req[i]){
			cout << "NO\n";
			return;
		}
	}
	
	if(mxreq[c[m-1]] == 0){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	
	int wrong;
	if(ids[c[m-1]].empty()){
		wrong = last[c[m-1]];
	}
	else{
		wrong = ids[c[m-1]][0];
	}
	
	rep(i,0,m){
		int x = c[i];
		if(ids[x].empty()){
			cout << wrong << " ";
		}
		else{
			cout << ids[x].back() << " ";
			ids[x].ppb();
		}
	}
	cout << "\n";
	
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