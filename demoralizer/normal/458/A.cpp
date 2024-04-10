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

vector<int> conv(string s){
	vector<int> a;
	for(char c:s){
		a.pb(c-'0');
	}
	reverse(all(a));
	return a;
}

void correct(int &x){
	if(x > 5) x = 5;
}

void solve(){
	string s,t;
	cin >> s >> t;
	vector<int> a = conv(s);
	vector<int> b = conv(t);
	
	while(a.back() == 0) a.ppb();
	while(b.back() == 0) b.ppb();
	
	if(sz(a) > sz(b) + 1){
		cout << ">";
		return;
	}
	if(sz(b) > sz(a) + 1){
		cout << "<";
		return;
	}
	
	while(sz(a)){
		if(sz(a) > sz(b)){
			if(sz(a) <= 2) break;
			int x = a.back();
			a.ppb();
			a.back() += x;
			a[sz(a) - 2] += x;
			// correct(a.back());
			// correct(a[a.size() - 2]);
		}
		else if(sz(a) < sz(b)){
			if(sz(b) <= 2) break;
			int x = b.back();
			b.ppb();
			b.back() += x;
			b[sz(b) - 2] += x;
			// correct(b.back());
			// correct(b[b.size() - 2]);
		}
		else{
			if(a.back() == b.back()){
				a.ppb();
				b.ppb();
			}
			else{
				int x = min(a.back(),b.back());
				a.back() -= x;
				b.back() -= x;
				if(a.back() > 1){
					cout << ">";
					return;
				}
				else if(b.back() > 1){
					cout << "<";
					return;
				}
				
				if(sz(a) <= 2) break;
				x = a.back();
				a.ppb();
				a.back() += x;
				a[sz(a) - 2] += x;
				
				x = b.back();
				b.ppb();
				b.back() += x;
				b[sz(b) - 2] += x;
				
			}
		}
	}
	
	if(sz(a) == sz(b)){
		if(sz(a) == 0){
			cout << "=";
			return;
		}
		if(a.back() > b.back()){
			cout << ">";
		}
		else{
			cout << "<";
		}
		return;
	}
	
	if(sz(a) > sz(b)){
		cout << ">";
	}
	else{
		cout << "<";
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