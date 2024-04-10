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
const int B = 340;

struct query
{
	int l,r,id;
	bool operator< (const query& other){
		if(l/B != other.l/B){
			return l/B < other.l/B;
		}
		return r < other.r;
	}
} q[N];

int a[N],b[N],ans[N];
int fa[12*N], fb[12*N];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,1,n+1){
		cin >> a[i];
		a[i] ^= a[i-1];
		b[i] = k ^ a[i-1];
	}
	rep(i,0,m){
		int l,r;
		cin >> l >> r;
		q[i] = {l,r,i};
	}
	sort(q,q+m);
	
	int val = (a[1] == b[1]);
	int l = 1, r = 1;
	fa[a[1]] = 1;
	fb[b[1]] = 1;
	rep(i,0,m){
		int id = q[i].id;
		int x = q[i].l;
		int y = q[i].r;
		
		while(r < y){
			r++;
			fa[a[r]]++;
			fb[b[r]]++;
			val += fb[a[r]];
		}
		while(l > x){
			l--;
			fa[a[l]]++;
			fb[b[l]]++;
			val += fa[b[l]];
		}
		while(r > y){
			val -= fb[a[r]];
			fa[a[r]]--;
			fb[b[r]]--;
			r--;
		}
		while(l < x){
			val -= fa[b[l]];
			fa[a[l]]--;
			fb[b[l]]--;
			l++;
		}
		
		ans[id] = val;
	}
	rep(i,0,m){
		cout << ans[i] << "\n";
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