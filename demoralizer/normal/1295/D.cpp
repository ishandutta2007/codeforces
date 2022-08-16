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
#ifdef demoralizer
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif


// int phi(int n) {
//     int result = n;
//     for (int i = 2; i * i <= n; i++) {
//         if(n % i == 0) {
//             while(n % i == 0)
//                 n /= i;
//             result -= result / i;
//         }
//     }
//     if(n > 1)
//         result -= result / n;
//     return result;
// }
void solve(){
	int a,m;
	cin>>a>>m;
	int g=__gcd(a,m);
	a/=g;
	m/=g;
	int zzz=m;
	// trace(g);
	vector<int> p;
	for(int i=2;i*i<=m;i++){
		if(m%i==0)p.pb(i);
		while(m%i==0)m/=i;
	}
	if(m!=1)p.pb(m);
	int n=sz(p);
	int ans1=0,ans2=0,b=a+zzz;
	rep(i,1,(1<<n)){
		int k=1;
		int r=ppc(i);
		r%=2;
		rep(j,0,n){
			if((1<<j)&i)k*=p[j];
		}
		// trace(r,i,k);
		if(r)ans1+=a/k;
		else ans1-=a/k;
		if(r)ans2+=b/k;
		else ans2-=b/k;
	}
	ans2=b-ans2;
	ans1=a-ans1;
	cout<<ans2-ans1<<"\n";
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