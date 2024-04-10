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

const double inf = 2 * INF;

const int N=0;

vector<int> tmp,v;

int pw(int a,int p){
	int result = 1;
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}

int sq(int x){
	int ans = sqrt(x);
	while(ans * ans < x){
		ans++;
	}
	while(ans * ans > x){
		ans--;
	}
	return ans;
}

void precompute(){
	rep(i,3,61){
		rep(j,2,INF){
			if(pow(j,i) >= inf){
				break;
			}
			tmp.pb(pw(j,i));
		}
	}
	sort(all(tmp));
	uniq(tmp);
	for(int x:tmp){
		int t = sq(x);
		if(t * t == x){
			continue;
		}
		v.pb(x);
	}
}

void solve(){
	int n;
	cin >> n;
	int ans = upper_bound(all(v),n) - v.begin();
	int x = sq(n) - 1;
	ans += x;
	ans = n - 1 - ans;
	cout << ans << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	precompute();
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}