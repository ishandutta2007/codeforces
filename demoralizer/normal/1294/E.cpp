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

void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+4][m+4];
	rep(i,0,n){
		rep(j,0,m){
			cin>>a[i][j];
			a[i][j]--;
		}
	}
	int ans=0;
	rep(j,0,m){
		int k=0;
		map<int, int> z;
		rep(i,0,n){
			int q=a[i][j]/m,r=a[i][j]%m;
			if(r!=j || a[i][j]>=n*m)continue;
			z[(2*n+i-q)%n]++;
		}
		k=n-z[0];
		// cout<<z[0]<<"\n";
		for(pii x:z){
			k=min(k,n-x.sc+x.fr);
			// cout<<i<<" "<<x<<"\n";
		}
		ans+=k;
	}
	cout<<ans;
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