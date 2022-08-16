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
// 0 -> ll, 1 -> lr, 2 -> ur, 3 -> ul


pii p[4];

int aux(int a){
	int ans = 0;
	pii z[4];
	rep(i,0,4){
		z[i] = p[i];
	}
	z[1].fr -= a;
	z[3].sc -= a;
	z[2].fr -= a;
	z[2].sc -= a;
	
	vector<int> v;
	rep(i,0,4){
		v.pb(z[i].fr);
	}
	sort(all(v));
	int m = v[1];
	for(int x:v){
		ans += abs(x - m);
	}
	
	v.clear();
	rep(i,0,4){
		v.pb(z[i].sc);
	}
	sort(all(v));
	m = v[1];
	for(int x:v){
		ans += abs(x - m);
	}
	
	return ans;
}

int answer(int a){
	int ans = INF;
	sort(p,p+4);
	do{
		amin(ans,aux(a));
	}while(next_permutation(p,p+4));
	return ans;
}

void solve(){
	int x[4],y[4];
	rep(i,0,4){
		cin >> p[i];
		x[i] = p[i].fr;
		y[i] = p[i].sc;
	}
	sort(x,x+4);
	sort(y,y+4);
	set<int> diffs;
	rep(i,0,4){
		rep(j,i,4){
			diffs.insert(x[j] - x[i]);
			diffs.insert(y[j] - y[i]);
		}
	}
	
	int ans = INF;
	
	
	for(int z:diffs){
		amin(ans,answer(z));
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
	return 0;//////
}