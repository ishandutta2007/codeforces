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
	int n;
	string s;
	cin >> n >> s;
	s += s;
	vector<int> pf(2*n+1);
	rep(i,0,2*n){
		pf[i + 1] = pf[i] + (s[i] == '(' ? 1 : - 1);
	}
	if(pf[n] != 0){
		cout << "0\n1 1";
		return;
	}
	
	map<int, vector<int>> m;
	rep(i,1,2*n+1){
		m[pf[i]].pb(i);
	}
	
	multiset<int> z;
	rep(i,0,n){
		z.insert(pf[i]);
	}
	
	auto how_many = [&](int val,int l,int r){
		vector<int> &v = m[val];
		return upper_bound(all(v),r) - lower_bound(all(v),l);
	};
	
	int pr = 0;
	int X = 1,Y = 1;
	rep(i,n,2*n){
		int zero = pf[i - n];
		z.erase(z.find(zero));
		z.insert(pf[i]);
		
		assert(pf[i] == zero);
		if(*z.begin() < zero - 2){
			continue;
		}
		
		int ans = how_many(zero, i-n+1, i);
		int x = i, y = i;
		if(how_many(zero - 1,i-n+1,i)){
			int l = *lower_bound(all(m[zero-1]),i-n+1);
			int r = *(upper_bound(all(m[zero-1]),i) - 1);
			ans += how_many(zero-2,l,r) - how_many(zero,l,r);
			x = l;
			y = r + 1;
		}
		if(ans > pr){
			pr = ans;
			X = (x - 1) % n + 1;
			Y = (y - 1) % n + 1;
		}
	}
	cout << pr << "\n";
	cout << X << " " << Y;
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