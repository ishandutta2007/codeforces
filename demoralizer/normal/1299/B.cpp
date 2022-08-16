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

const int N=1e5+5;

int x[N],y[N],l[N];
pii s[N];
bool cmp(pii a,pii b){
	return abs(a.fr*b.sc)==abs(b.fr*a.sc);
}
void solve(){
	int n;
	cin>>n;
	if(n%2){
		cout<<"NO";
		return;
	}
	rep(i,0,n)cin>>x[i]>>y[i];
	x[n]=x[0];
	y[n]=y[0];
	rep(i,0,n){
		l[i]=(x[i+1]-x[i])*(x[i+1]-x[i]) + (y[i+1]-y[i])*(y[i+1]-y[i]);
		s[i]={y[i+1]-y[i],x[i+1]-x[i]};
	}
	rep(i,0,n/2){
		if(l[i]!=l[i+n/2] || !cmp(s[i],s[i+n/2])){
			cout<<"NO";
			return;
		}
	}
	cout<<"YES";
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
	// cin>>t;
	while(t--) solve();
	return 0;
}