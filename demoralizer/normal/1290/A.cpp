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

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

const int N=3505;
int a[N];
void solve(){
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	k=min(k,m-1);
	vector<int> v;
	rep(i,0,n)cin>>a[i];
	int r=n-m;
	rep(i,0,m){
		v.pb(max(a[i],a[i+r]));
	}
	r=m-k;
	multiset<int> s;
	for(int i=0;i<r;i++){
		s.insert(v[i]);
	}
	ans=*s.begin();
	for(int i=r;i<sz(v);i++){
		s.erase(s.find(v[i-r]));
		s.insert(v[i]);
		ans=max(ans,*s.begin());
	}
	cout<<ans<<"\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}