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

const int N=0;

void solve(){
	int ans=0,n;
	string a,b;
	cin>>n>>a>>b;
	rep(i,0,n/2){
		map<char, int> m;
		m[a[i]]++;
		m[b[i]]++;
		m[a[n-1-i]]++;
		m[b[n-1-i]]++;
		int c=0;
		for(auto x:m){
			c+=x.sc%2;
		}
		if(c){
			c=2;
			if(a[i]==b[i] || a[n-1-i]==b[i] || b[n-1-i]==a[i] || b[n-1-i]==a[n-1-i] || b[i]==b[n-1-i])c=1;
		}
		ans+=c;
	}
	if(n%2)ans+=(a[n/2]!=b[n/2]);
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