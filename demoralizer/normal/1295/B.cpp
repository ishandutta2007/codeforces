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
	int n,x;
	cin>>n>>x;
	string s;
	cin>>s;
	int b=0;
	map<int, int> m;
	m[0]=1;
	rep(i,0,n){
		if(s[i]=='0')b++;
		else b--;
		if(i<n-1)m[b]++;
	}
	if(b==0){
		if(m[x])cout<<-1;
		else cout<<0;
		cout<<"\n";
		return;
	}
	int ans=0;
	for(auto k:m){
		// if((k.fr-x)*b)
		// if(k.fr==x)ans+=k.sc;
		// cout<<k<<"\n";
		int t=(x-k.fr)/b;
		if(t<0)continue;
		if(t*b!=(x-k.fr))continue;
		ans+=k.sc;
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