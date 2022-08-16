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

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=5e5+5;

int a[N];
int b[N];
int c[N];
int m[N];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n)cin>>m[i];
	vector<pii> v;
	v.pb({m[0],1});
	a[0]=m[0];
	int t=a[0];
	rep(i,1,n){
		pii k={m[i],1};
		while(!v.empty() && k.fr<=v.back().fr){
			pii u=v.back();
			v.ppb();
			k.sc+=u.sc;
			t-=u.fr*u.sc;
		}
		v.pb(k);
		t+=k.fr*k.sc;
		a[i]=t;
	}
	v.clear();
	
	v.pb({m[n-1],1});
	b[n-1]=m[n-1];
	t=b[n-1];
	for(int i=n-2;i>=0;i--){
		pii k={m[i],1};
		while(!v.empty() && k.fr<=v.back().fr){
			pii u=v.back();
			v.ppb();
			k.sc+=u.sc;
			t-=u.fr*u.sc;
		}
		v.pb(k);
		t+=k.fr*k.sc;
		b[i]=t;
	}
	int ans=a[0]+b[0]-m[0];
	int id=0;
	rep(i,0,n){
		if(ans<a[i]+b[i]-m[i]){
			ans=a[i]+b[i]-m[i];
			id=i;
		}
	}
	c[id]=m[id];
	rep(i,id+1,n){
		c[i]=min(c[i-1],m[i]);
	}
	for(int i=id-1;i>=0;i--){
		c[i]=min(c[i+1],m[i]);
	}
	rep(i,0,n){
		cout<<c[i]<<" ";
	}
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