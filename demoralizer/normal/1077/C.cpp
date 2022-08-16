#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<typename T1,typename T2>std::istream& operator>>(std::istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a){out<<a.fr<<" "<<a.sc;return out;}

const int N=2e5+5;
int a[N],b[5*N];
vector<int> v;
void solve(){
	int n,s=0;
	cin>>n;
	rep(i,0,n)cin>>a[i],b[a[i]]++,s+=a[i];
	rep(i,0,n){
		s-=a[i];
		b[a[i]]--;
		if(s%2==0 && s/2<5*N && b[s/2])v.pb(i);
		b[a[i]]++;
		s+=a[i];
	}
	cout<<sz(v)<<"\n";
	for(int x:v)cout<<x+1<<" ";
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}