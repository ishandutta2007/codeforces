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

int t[N],x[N];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> t[i] >> x[i];
	}
	t[n] = INF;
	
	int cc = 0;
	int curt = t[0], curx = 0;
	int dir = 0;
	int stp;
	
	int ans = 0;
	
	while(cc < n){
		// cout << curt << " " << curx << " " << dir << "\n";
		int nt = t[cc];
		if(dir){
			if(stp <= nt){
				curx += dir * (stp - curt);
				// cout << curx << "\n";
				curt = stp;
				dir = 0;
				continue;
			}
			else{
				curx += dir * (nt - curt);
				curt = nt;
				int tim = min(t[cc+1],stp) - t[cc];
				if(curx == x[cc] || (abs(x[cc] - curx) <= tim && (x[cc] - curx) * dir > 0)){
					ans++;
				}
				cc++;
				continue;
			}
		}
		else{
			curt = t[cc];
			int diff = abs(curx - x[cc]);
			stp = curt + diff;
			if(curx < x[cc]){
				dir = 1;
			}
			else if(curx > x[cc]){
				dir = -1;
			}
			else{
				dir = 0;
			}
			
			int tim = min(stp,t[cc+1]) - t[cc];
			if(curx == x[cc] || (abs(x[cc] - curx) <= tim && (x[cc] - curx) * dir > 0)){
				ans++;
			}
			
			cc++;
		}
	}
	
	
	cout << ans << "\n";
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