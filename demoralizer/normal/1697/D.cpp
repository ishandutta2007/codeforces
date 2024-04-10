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

char query(int i){
	i++;
	cout << "? 1 " << i << endl;
	string s;
	cin >> s;
	return s[0];
}

int query(int l, int r){
	l++;
	r++;
	cout << "? 2 " << l << " " << r << endl;
	int ans;
	cin >> ans;
	return ans;
}

void answer(string s){
	cout << "! " << s << endl;
}

void solve(){
	int n;
	cin >> n;
	
	string s;
	s.push_back(query(0));
	
	set<int> relevant;
	relevant.insert(0);
	
	rep(i,1,n){
		vector<int> v(all(relevant));
		
		int L = 0, U = sz(v) - 1;
		int ans = -1;
		while(L <= U){
			int m = (L + U) / 2;
			
			if(query(v[m],i) == (sz(v) - m)){
				ans = m;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
		if(ans == -1){
			s.push_back(query(i));
		}
		else{
			s.push_back(s[v[ans]]);
			relevant.erase(v[ans]);
		}
		relevant.insert(i);
	}
	answer(s);
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