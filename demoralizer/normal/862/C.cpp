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

const int N=1e5+5;



void solve(){
	int n,x;
	cin>>n>>x;
	int a = (1<<17);
	int b = (1<<18);
	if(n%4==1){
		cout<<"YES\n";
		rep(i,0,n-1){
			cout<<a+i<<" ";
		}
		cout<<x;
		return;
	}
	if(n%4==2){
		if(!x){
			if(n==2){
				cout<<"NO";
				return;
			}
			cout<<"YES\n";
			rep(i,0,n-6){
				cout<<a+i<<" ";
			}
			cout<<"0 1 4 6 8 11";
		}
		else{
			cout<<"YES\n";
			rep(i,0,n-2){
				cout<<a+i<<" ";
			}
			cout<<"1 "<<(x^1);
		}
		return;
	}
	if(n%4==3){
		cout<<"YES\n";
		rep(i,0,n-3){
			cout<<a+i<<" ";
		}
		cout<<(x^1)<<" "<<b<<" "<<(b^1);
		return;
	}
	cout<<"YES\n";
	rep(i,0,n-4){
		cout<<a+i<<" ";
	}
	cout<<"0 "<<(x^(x+1))<<" "<<b<<" "<<(b^(x+1));
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