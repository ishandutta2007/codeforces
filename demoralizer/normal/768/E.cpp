#include <bits/stdc++.h>
using namespace std;
// #define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

int nimber[61];

map<int, int> m[61];int cnt=0;

int calc(int x,int mask=0){
	if(x==0)return 0;
	mask&=(1LL<<(x+1))-1;
	if(m[x].count(mask))return m[x][mask];
	set<int> s;
	rep(i,0,x+1)s.insert(i);
	rep(i,1,x+1){
		if(i>30){
			s.erase(calc(x-i,mask));
			continue;
		}
		if((mask>>i)&1)continue;
		s.erase(calc(x-i,mask|(1LL<<i)));
	}
	m[x][mask]=*s.begin();
	return *s.begin();
}

void solve(){
	rep(i,1,61){
		nimber[i]=calc(i);
	}
	int n,ans=0;
	cin>>n;
	rep(i,0,n){
		int s;
		cin>>s;
		ans^=nimber[s];
	}
	if(ans==0)cout<<"YES";
	else cout<<"NO";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}