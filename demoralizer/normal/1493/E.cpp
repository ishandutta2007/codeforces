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
	string l,r;
	cin >> n >> l >> r;
	
	if(r == "0"){
		cout << 0;
		return;
	}
	
	int fz = 0;
	while(fz < n && r[fz] != '0'){
		fz++;
	}
	
	if(fz == n){
		cout << r;
		return;
	}
	
	int fo = 0;
	while(fo < n && l[fo] != '1'){
		fo++;
	}
	
	if(fo != 0){
		rep(i,0,n){
			cout << 1;
		}
		return;
	}
	
	if(r.back() == '1'){
		cout << r;
		return;
	}
	
	
	int gap = 0;
	while(gap < 2 && l < r){
		for(int i = n - 1; i >= 0; i--){
			if(l[i] == '0'){
				l[i] = '1';
				break;
			}
			else{
				l[i] = '0';
			}
		}
		gap++;
	}
	
	if(gap == 2){
		rep(i,0,n-1){
			cout << r[i];
		}
		cout << 1;
	}
	else{
		cout << r;
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