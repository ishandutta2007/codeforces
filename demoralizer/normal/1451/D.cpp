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
	int d,k;
	cin >> d >> k;
	
	if(k > d){
		cout << "Utkarsh\n";
		return;
	}
	
	int h = 0;
	int turn = 1; // 1 = first
	while(h <= min(d,k)){
		// x = y + h
		
		int L = 0, U = 2e5+2;
		int ans;
		while(L <= U){
			int m = (L + U) / 2;
			int X = h + m * k;
			int Y = m * k;
			if(max(X,Y) <= d && X * X + Y * Y <= d * d){
				ans = m;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
		
		int X = h + ans * k, Y = ans * k;
		L = 0, U = 2e5+2;
		while(L <= U){
			int m = (L + U) / 2;
			int X_ = X + m * k;
			if(max(X_,Y) <= d && X_ * X_ + Y * Y <= d * d){
				ans = m;
				L = m + 1;
			}
			else{
				U = m - 1;
			}
		}
		
		if(ans % 2){
			// turn wins
			if(h == k){
				cout << "Utkarsh\n";
				return;
			}
		}
		else{
			if(h == 0){
				cout << "Utkarsh\n";
				return;
			}
		}
		
		h += k;
		turn = !turn;
	}
	// turn lost
	// if(turn == 1){
	// 	cout << "Utkarsh\n";
	// }
	// else{
		cout << "Ashish\n";
	// }
	return;
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